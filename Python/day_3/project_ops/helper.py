
from data_ops import load


def get_my_projects(email: str):
    projects = load("projects")
    print()
    user_projects = []
    for project in projects:
        if project["user"] == email:
            user_projects.append(project)
    return user_projects


def select_user_project(projects, email):
    while True:
        project_id = input("Enter the project ID: ")
        if not project_id.isdigit():
            print("Enter a valid project ID.")
            continue
        project_id = int(project_id)

        for idx, project in enumerate(projects):
            if project['id'] == project_id and project['user'] == email:
                return idx

        print("Project ID not found. Please try again.")