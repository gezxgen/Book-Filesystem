# Test Protocol for Book Database Management Program

**Program Name**: Book Database Management Program  
**Filename**: `main.c`  
**Author**: Kevin  
**Test Date**: 06.10.2024

---

## Objective:
To thoroughly test the functionality and robustness of the **Book Database Management Program**, ensuring all features work as intended, including edge cases such as invalid inputs or data limits.

## Test Environment:
- **Operating System**: [Insert OS used for testing]
- **Compiler**: [Insert Compiler (e.g., GCC, Clang)]
- **Hardware Specs**: [Insert Processor, RAM, etc.]
- **Input Methods**: Console input for menu selection and data entry.

---

## Test Cases:

### **Test Case 1**: Program Initialization and Menu Display
- **Description**: Test the correct initialization of the program and whether the main menu is displayed.
- **Steps**:
    1. Compile and run `main.c`.
    2. Verify that the program initializes and displays the main menu.
- **Expected Output**:
    - Program should print the main menu options (0-5) clearly.
    - No errors or unexpected outputs.
- **Status**: [Pass / Fail]
- **Notes**: [Insert any additional information]

### **Test Case 2**: Adding a Book
- **Description**: Test adding a new book to the database.
- **Steps**:
    1. Choose the menu option "1: Add a book."
    2. Enter valid book details (Title, Author, Pages, Price).
    3. Verify that the book is correctly added to the database.
- **Expected Output**:
    - Program should accept the inputs without errors and store the book in the database.
    - The book details should be accessible via the print or search function.
- **Status**: [Pass / Fail]
- **Notes**: [Insert any additional information]

### **Test Case 3**: Adding Books Beyond Database Capacity
- **Description**: Test attempting to add a book when the database is full.
- **Steps**:
    1. Add 10 books (maximum capacity).
    2. Attempt to add an 11th book.
- **Expected Output**:
    - Program should display a message saying no more space is available for new books.
    - Program should not crash or display unexpected behavior.
- **Status**: [Pass / Fail]
- **Notes**: [Insert any additional information]

### **Test Case 4**: Deleting a Book
- **Description**: Test deleting an existing book from the database.
- **Steps**:
    1. Add a book.
    2. Choose the menu option "2: Delete a book."
    3. Enter the title of the book to delete.
    4. Verify that the book is deleted from the database.
- **Expected Output**:
    - The book should be removed from the list.
    - The rest of the books should shift accordingly.
    - Deletion confirmation message should be shown.
- **Status**: [Pass / Fail]
- **Notes**: [Insert any additional information]

### **Test Case 5**: Deleting a Non-Existent Book
- **Description**: Test deleting a book that doesn't exist in the database.
- **Steps**:
    1. Attempt to delete a book that is not present.
- **Expected Output**:
    - Program should display a message indicating that the book could not be found.
    - No changes should be made to the database.
- **Status**: [Pass / Fail]
- **Notes**: [Insert any additional information]

### **Test Case 6**: Searching for a Book
- **Description**: Test searching for an existing book by title.
- **Steps**:
    1. Add a book to the database.
    2. Choose the menu option "3: Search for a book."
    3. Enter the title of the book to search.
- **Expected Output**:
    - Program should correctly display the details of the book.
- **Status**: [Pass / Fail]
- **Notes**: [Insert any additional information]

### **Test Case 7**: Searching for a Non-Existent Book
- **Description**: Test searching for a book that does not exist in the database.
- **Steps**:
    1. Attempt to search for a book that is not in the database.
- **Expected Output**:
    - Program should display a message indicating that the book was not found.
- **Status**: [Pass / Fail]
- **Notes**: [Insert any additional information]

### **Test Case 8**: Displaying All Books
- **Description**: Test displaying all books in the database.
- **Steps**:
    1. Add multiple books to the database.
    2. Choose the menu option "5: Display all books."
- **Expected Output**:
    - Program should list all books with correct details (Title, Author, Pages, Price).
    - The formatting of the output should be correct.
- **Status**: [Pass / Fail]
- **Notes**: [Insert any additional information]

### **Test Case 9**: Calculating Average Number of Pages
- **Description**: Test the calculation of the average number of pages in the database.
- **Steps**:
    1. Add multiple books with varying numbers of pages.
    2. Choose the menu option "4: Calculate average pages."
- **Expected Output**:
    - Program should correctly calculate and display the average number of pages.
- **Status**: [Pass / Fail]
- **Notes**: [Insert any additional information]

### **Test Case 10**: Input Validation for Pages and Price
- **Description**: Test input validation for non-integer page values and non-float price values.
- **Steps**:
    1. Attempt to add a book with invalid page or price input (e.g., letters or symbols).
- **Expected Output**:
    - Program should reject invalid input and prompt the user to enter valid data.
    - No data should be stored unless valid inputs are provided.
- **Status**: [Pass / Fail]
- **Notes**: [Insert any additional information]

### **Test Case 11**: Graceful Exit
- **Description**: Test the graceful exit of the program.
- **Steps**:
    1. Choose the menu option "0: Exit the program."
- **Expected Output**:
    - Program should exit cleanly without errors or crashes.
- **Status**: [Pass / Fail]
- **Notes**: [Insert any additional information]

---

## Additional Test Notes:
- Ensure that `fgets()` and `scanf()` calls are handled properly to avoid input buffer issues.
- Test edge cases with large numbers of pages or price values to verify handling of data limits.
- Check for memory leaks or crashes using a tool like Valgrind or similar, especially when adding and deleting books.

---
