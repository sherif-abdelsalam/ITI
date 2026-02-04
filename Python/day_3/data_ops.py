import json 

def load(filename):
    try:
        with open(f"file_storage/{filename}.json", "r") as f:
            return json.load(f)

    except FileNotFoundError:
        return []

    except json.JSONDecodeError:
        return []


def save(file, data):
    with open(f"file_storage/{file}.json", "w") as file:
        json.dump(data, file, indent=4)


def display_projects(projects):
    if not projects:
        print("\n\nNo projects found.")
        return

    print(f"{'\n\nId':<5} {'Title':<20} {'Details':<30} {'Total Target':<15} {'Start Date':<12} {'End Date':<12} {'User':<25}")
    print("-" * 120)
    for project in projects:
        print(f"{project['id']:<5} {project['title']:<20} {project['details']:<30} {project['total_target']:<15} {project['start_date']:<12} {project['end_date']:<12} {project['user']:<25}")