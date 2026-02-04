
from data_ops import display_projects
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