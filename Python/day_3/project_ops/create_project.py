import json
from validations.project_validation import validate_details, validate_title, validate_total_target
from system_methods import pause_for_1_seconds
from validations.check_date import validate_date, validate_end_date_range
from data_ops import load, save

def get_project_data():

    title = input("Enter project title: ")
    title = validate_title(title)

    details = input("Enter project details: ")
    details = validate_details(details)

    total_target = input("Enter total target amount: ")
    total_target = validate_total_target(total_target)

    start_date = input("Enter start date (YYYY-MM-DD): ")
    start_date = validate_date(start_date)

    end_date = input("Enter end date (YYYY-MM-DD): ")
    end_date = validate_end_date_range(start_date, end_date)

    project_data = {
        "title": title,
        "details": details,
        "total_target": total_target,
        "start_date": start_date,
        "end_date": end_date
    }

    return project_data
        
def create_project(email):

    project_data = get_project_data()
    
    projects = load("projects")
    project_data["user"] = email
    project_data["id"] = len(projects) + 1 
    projects.append(project_data)
    save("projects", projects)

    print("Project created successfully.")
    pause_for_1_seconds()
    input("\n\nPress Enter to return to the main menu...")

