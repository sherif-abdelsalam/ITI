from data_ops import load, save, display_projects
from project_ops.helper import get_my_projects, select_user_project


def delete_my_project(email: str):
    projects = get_my_projects(email)
    display_projects(projects)

    if not projects:
        print("No projects available to delete.")
        input("\n\nPress Enter to return to the main menu...")
        return

    print("*" * 40)


    project_idx = select_user_project(projects, email)
    project_title = projects[project_idx]['title']

    all_projects = load("projects")
    all_projects.remove(projects[project_idx])
    save("projects", all_projects)

    print(f"Project '{project_title}' has been deleted successfully.")
    input("\n\nPress Enter to return to the main menu...")
