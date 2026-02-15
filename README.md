# Hotel Reservation System Project_using C Language

This **Hotel Reservation System** is a project designed to simulate the process of reserving, canceling, and managing hotel rooms. It has been developed using **C** programming language and the **Code::Blocks IDE** for the **Computer Programming 1** course.
It simulates a real hotel booking system where hotel staff can manage reservations, view room availability, and generate reports.

## Functionality
The system offers the following functionalities:
1. **Login/Logout**: Admin login with authentication. Only hotel staff can access the system's features.
2. **View Hotel Information**: Displays details about the hotel's amenities and room types.
3. **Room Availability**: Shows available rooms of different types.
4. **Room Reservation**: Allows staff to make reservations for customers by entering the customer's details and the desired booking dates.
5. **Reservation Report**: Generates a report of all existing reservations, including customer names, dates, room types, and total bills.

## Instructions
1. **Running the Program**: 
   - Run the program using a C compiler.
   - Upon launch, the user is prompted to either exit the program or choose to log in as a staff member.
   
2. **Login System**:
   - The system asks for a password to authenticate users. Admin access is granted if the password `admin` is entered correctly within 3 attempts.
   - After logging in, users can view room availability, make reservations, or log out.

3. **Making Reservations**:
   - The user inputs customer details and selects a room type (Suit, King, or Travel).
   - The system checks room availability and updates the number of available rooms accordingly.
   - A bill is generated based on the room type, number of days, and number of rooms reserved.

4. **Reservation Report**:
   - The report function displays all the reservations made, including customer names, booking dates, room types, and bills.

5. **Exit**: 
   - The system can be exited by choosing the 'Exit' option from the menu.

## Limitations/Faults
1. **Authentication**: 
   - Currently, the login system only uses a fixed password (`admin`). There is no functionality for different staff roles or user-specific logins.
   
2. **Error Handling**: 
   - While the system does check for valid inputs (e.g., dates), there is limited error handling for incorrect room types or invalid data entries.

3. **File Handling**: 
   - The system saves reservation data to a file, but only appends data without the ability to modify or cancel existing reservations.

## Future Improvements
1. **Cancellation and Modification of Reservations**:
   - Add functionality to allow customers or staff to cancel or modify existing reservations.
   
2. **User Management**:
   - Implement a user management system where staff can create unique accounts with different roles (e.g., receptionist, admin).
   
3. **Search Feature**:
   - Add a search functionality to quickly find reservations by customer name or reservation ID.
  
## Contributors 
- Nusrath Jahan Shawon 
- Sumaia Tarannoom Mahi 
- Suraia Tabassoom Ruhi 
- Sabiha Jannat
