from datetime import datetime, date


def check_date_format(date_str: str):
    try:
        parsed_date = datetime.strptime(date_str, "%Y-%m-%d").date()
        today = date.today()
        return parsed_date >= today
    except ValueError:
        return False


def validate_date(date_str: str):
    while not check_date_format(date_str):
        print("Invalid date. use (YYYY-MM-DD) and not in the past.")
        date_str = input("Enter start date (YYYY-MM-DD): ")
    return date_str


def validate_end_date_range(start_date: str, end_date: str):
    start = datetime.strptime(start_date, "%Y-%m-%d").date()

    while True:
        try:
            end = datetime.strptime(end_date, "%Y-%m-%d").date()

            if end < start:
                print("End date must be after start date.")
                end_date = input("Enter end date (YYYY-MM-DD): ")
                continue

            if end < date.today():
                print("End date cannot be in the past.")
                end_date = input("Enter end date (YYYY-MM-DD): ")
                continue

            return end_date

        except ValueError:
            print("Invalid format. Use YYYY-MM-DD")
            end_date = input("Enter end date (YYYY-MM-DD): ")
