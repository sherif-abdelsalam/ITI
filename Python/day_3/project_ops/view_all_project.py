from data_ops import display_projects, load


def view_all_projects():
    projects = load("projects")
    display_projects(projects)
    input("\n\nPress Enter to return to the main menu...")