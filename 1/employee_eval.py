import csv

employee_fields = ['Emp_ID', 'name', 'age', 'email', 'phone', 'jobKnowledge', 'communicationSkills', 'teamwork','problemSolvin','productivity']
employee_database = 'employees.csv'

def display_menu():
    print("--------------------------------------")
    print(" Welcome to Employee Performance Evaluation System")
    print("---------------------------------------")
    print("1. Add New Employees")
    print("2. View Employee")
    print("3. Search Employee Details")
    print("4. Update Employee Details")
    print("5. Delete Employee")
    print("6. Employee evaluation")
    print("7. Quit")

def add_employee():
    print("-------------------------")
    print("Add Employee Information")
    print("-------------------------")
    global employee_fields
    global employee_database
 
    employee_data = []
    for field in employee_fields:
        value = input("Enter " + field + ": ")
        employee_data.append(value)
 
    with open(employee_database, "a", encoding="utf-8") as f:
        writer = csv.writer(f)
        writer.writerows([employee_data])
 
    print("Data saved successfully")
    input("Press any key to continue")
    return
 
def view_employee():
    global employee_fields
    global employee_database
 
    print("--- Employee Records ---")
 
    with open(employee_database, "r", encoding="utf-8") as f:
        reader = csv.reader(f)
        for x in employee_database:
            print(x, end='\t |')
        print("\n-----------------------------------------------------------------")
 
        for row in reader:
            for item in row:
                print(item, end="\t |")
            print("\n")
 
    input("Press any key to continue")

def search_employee():
    global employee_fields
    global employee_database
 
    print("--- Search Employee ---")
    empid = input("Enter Employee ID to search: ")
    with open(employee_database, "r", encoding="utf-8") as f:
        reader = csv.reader(f)
        for row in reader:
            if len(row) > 0:
                if empid == row[0]:
                    print("----- employee Found -----")
                    print("Emp_ID ", row[0])
                    print("Name: ", row[1])
                    print("Age: ", row[2])
                    print("Email: ", row[3])
                    print("Phone: ",row[4])
                    print("jobKnowledge: ", row[5])
                    print("communicationSkills: ", row[6])
                    print("teamwork: ", row[7])
                    print("problemSolvin: ", row[8])
                    print("productivity: ", row[9])
                    break
        else:
            print("Emp_ID not found in our database")
    input("Press any key to continue")

def update_employee():
    global employee_fields
    global employee_database

    print("--- Update employee ---")
    empid = input("Enter Emp_ID to update: ")
    index_employee = None
    updated_data = []
    with open(employee_database, "r", encoding="utf-8") as f:
        reader = csv.reader(f)
        counter = 0
        for row in reader:
            if len(row) > 0:
                if empid == row[0]:
                    index_employee = counter
                    print("employee Found: at index ",index_employee)
                    employee_data = []
                    for field in employee_fields:
                        value = input("Enter " + field + ": ")
                        employee_data.append(value)
                    updated_data.append(employee_data)
                else:
                    updated_data.append(row)
                counter += 1

    # Check if the record is found or not
    if index_employee is not None:
        with open(employee_database, "w", encoding="utf-8") as f:
            writer = csv.writer(f)
            writer.writerows(updated_data)
    else:
        print("Emp_ID not found in our database")
 
    input("Press any key to continue")

def delete_employee():
    global employee_fields
    global employee_database

    print("--- Delete Employee ---")
    empid = input("Enter Emp_ID to delete: ")
    employee_found = False
    updated_data = []
    with open(employee_database, "r", encoding="utf-8") as f:
        reader = csv.reader(f)
        counter = 0
        for row in reader:
            if len(row) > 0:
                if empid != row[0]:
                    updated_data.append(row)
                    counter += 1
                else:
                    employee_found = True

    if employee_found is True:
        with open(employee_database, "w", encoding="utf-8") as f:
            writer = csv.writer(f)
            writer.writerows(updated_data)
        print("Emp_ID ", empid, "deleted successfully")
    else:
        print("Emp_ID not found in our database")

    input("Press any key to continue")

def eval_employee():
    global employee_fields
    global employee_database

    print("--- Evaluate Employee ---")
    empid = input("Enter Employee ID to Evaluate: ")
    with open(employee_database, "r", encoding="utf-8") as f:
        reader = csv.reader(f)
        for row in reader:
            if len(row) > 0:
                if empid == row[0]:
                    a = (float(row[5])+float(row[6])+float(row[7])+float(row[8])+float(row[9]))/5
                    print("Overall Score: ",a)
                    if(a>=8):
                        print("Eligible for promotion.")
                    elif(a>=6 and a<8):
                        print("Eligible for raise")
                    elif(a>=4 and a<6):
                        print("No promotion, No raise")
                    elif(a>=0 and a<4):
                        print("Fire")
                    break
        else:
            print("Emp_ID not found in our database")
    input("Press any key to continue") 

while True:
    display_menu()

    choice = input("Enter your choice: ")
    if choice == '1':
        add_employee()
    elif choice == '2':
        view_employee()
    elif choice == '3':
        search_employee()
    elif choice == '4':
        update_employee()
    elif choice == '5':
        delete_employee()
    elif choice == '6':
        eval_employee()
    else:
        break
print("-------------------------------")
print(" Thank you for using our system")
print("-------------------------------")