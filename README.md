# Hotel Reservation System Project_using C Language

This Hotel Reservation System is a console-based application developed using the C programming language for the Computer Programming 1 course.
It simulates a real hotel booking system where hotel staff can manage reservations, view room availability, and generate reports.

# Features

-**Admin Login System**
Only staff members can access the system using a password (admin).

-**Hotel Information**
Displays hotel amenities, location, and room details.

-**Room Availability**
Shows available rooms by category:

-Suit

-King

-Travel

-**Room Reservation**
Staff can:

Enter customer details

-Select room type

-Choose reservation date

-Specify number of days and guests

-Automatically generate a bill

-**Reservation Report**
Displays all stored reservations including:

-Customer name

-Date

-Room type

-Number of rooms

-Total bill

-**File Storage**
Reservation data is saved in a text file (reservationData.txt) and loaded automatically on program start.

# How to Run the Program

1.Compile the program using any C compiler (GCC / Code::Blocks / Dev-C++).

2.Run the executable file.

3.Choose:

-S → Staff login

-E → Exit program

# Login Information

-**Password:** admin

-Maximum **3 attempts** allowed.

After successful login, the main menu appears.

# How Reservation Works

1.Enter customer first name and last name.

2.Enter booking date (dd/mm/yyyy).

3.Choose room type:

-S → Suit

-K → King

-T → Travel

4.Enter:

-Number of days

-Number of people

5.System calculates:

-Required rooms

-Total bill

6.Reservation is saved automatically to file.

# Technologies Used

-Language: C

-IDE: Code::Blocks

-Concepts Used:

-Structures

-File handling

-Conditional logic

-Functions

-Date validation

-ANSI escape codes (for UI)

# Limitations

-Fixed admin password (admin)

-No reservation cancellation feature

-No search by name or ID

-File only appends data (no edit/delete)

-Windows-only UI (uses system("cls") and getch())

# Future Improvements

-Add reservation cancellation

-Add search by customer name or ID

-Multiple staff accounts

-Use database instead of text file

-Convert to GUI (C++ / Java / Python)

# Contributors

-Nusrath Jahan Shawon

-Sumaia Tarannoom Mahi

-Suraia Tabassoom Ruhi

-Sabiha Jannat
