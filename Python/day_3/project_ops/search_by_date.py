
from datetime import date
from validations.check_date import validate_date
from data_ops import load, display_projects

def get_date():
    date = input("Enter date to search by (YYYY-MM-DD): ")
    date = validate_date(date)
    return date

def search_by_date():
    search_date = get_date()
    all_projects = load("projects")
    founded_projects = []
    for project in all_projects:
        if project['start_date'] <= search_date <= project['end_date']:
            founded_projects.append(project)
    if founded_projects:
        display_projects(founded_projects)
    else:
        print("No projects found for the given date.")

        
    input("\n\nPress Enter to return to the main menu...")


