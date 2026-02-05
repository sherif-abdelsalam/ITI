
from data_ops import display_projects, load, save
from validations.check_date import validate_date, validate_end_date_range
from validations.project_validation import validate_details, validate_title, validate_total_target
from project_ops.helper import get_my_projects, select_user_project



def edit_user_project(email: str):
    projects = get_my_projects(email)
    display_projects(projects)

    if not projects:
        print("No projects available to edit.")
        input("\n\nPress Enter to return to the main menu...")
        return

    print("*" * 40)


    project_idx = select_user_project(projects, email)
    project = projects[project_idx]

    print("\n\nDo you want to edit the title? (y/n): ", end="")
    if input().lower() == 'y':
        new_title = input("Enter new title: ")
        validate_title(new_title)
        project['title'] = new_title
    
    print("Do you want to edit the details? (y/n): ", end="")
    if input().lower() == 'y':
        new_details = input("Enter new details: ")
        validate_details(new_details)
        project['details'] = new_details

    print("Do you want to edit the total target? (y/n): ", end="")
    if input().lower() == 'y':
        new_total_target = input("Enter new total target: ")
        validate_total_target(new_total_target)
        project['total_target'] = new_total_target
    
    print("Do you want to edit the start date? (y/n): ", end="")
    if input().lower() == 'y':
        new_start_date = input("Enter new start date: ")
        validate_date(new_start_date)
        project['start_date'] = new_start_date

    print("Do you want to edit the end date? (y/n): ", end="")
    if input().lower() == 'y':
        new_end_date = input("Enter new end date: ")
        validate_end_date_range(new_start_date,new_end_date)
        project['end_date'] = new_end_date

    all_projects = load("projects")
    for idx, proj in enumerate(all_projects):
        if proj['id'] == project['id'] and proj['user'] == email:
            all_projects[idx] = project
            break

    save("projects", all_projects)
    
    print(f"Project '{project['title']}' has been updated successfully.")
    input("\n\nPress Enter to return to the main menu...")
