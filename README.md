```markdown
# Course Repository: CSE 2100 - Advanced Programming Laboratory

Welcome to the **CSE 2100 - Advanced Programming Laboratory** GitHub repository! This repository hosts a series of tasks designed to enhance programming skills, enforce coding standards, and implement modern software design principles.

## Repository Structure

cseku_apl_24_230218/
│
├── task1/
│   ├── BinarySearchTree_Old.cpp
│   ├── DivisorCount_Old.cpp
│   ├── DoublyLinkedList_Old.c
│   ├── MergeSort_Old.cpp
│   └── SegmentedSieve_Old.cpp
│
├── task2/
│   └── My_Anime_List/
│       ├── src/
│       │   ├── main/
│       │   │   ├── java/
│       │   │   │   ├── model/
│       │   │   │   ├── repository/
│       │   │   │   ├── service/
│       │   │   │   └── ui/
│       │   └── test/
│       │       ├── java/
│       │       │   ├── model/
│       │       │   ├── repository/
│       │       │   └── service/
│       └── README.md
│
└── task3/
    └── My_Anime_List(MVC)/
        ├── src/
        │   ├── model/
        │   │   └── Anime.java            
        │   ├── repository/
        │   │   └── AnimeRepository.java  
        │   ├── service/
        │   │   └── AnimeService.java     
        │   ├── filter/
        │   │   ├── FilterStrategy.java   
        │   │   ├── GenreFilter.java      
        │   │   └── RatingFilter.java    
        │   ├── display/
        │   │   ├── Displayable.java      
        │   │   └── AnimeDisplayService.java 
        │   └── Main.java                      
        └── README.md

## Tasks Overview

This repository is organized by tasks, each designed to build programming skills progressively. Each task folder contains source code, documentation, and related resources to complete the assignment.

### Task 1: Refactoring Legacy Code

#### Description
In Task 1, the goal is to refactor legacy code files from previous years’ assignments, updating them to align with modern coding standards and best practices. This includes enhancing readability, reducing complexity, and improving maintainability without changing the core functionality.

#### Files

- `BinarySearchTree_Old.cpp`
- `DivisorCount_Old.cpp`
- `DoublyLinkedList_Old.c`
- `MergeSort_Old.cpp`
- `SegmentedSieve_Old.cpp`

#### Objective
Refactor each of these files by applying coding styles and conventions discussed in Week 1 of the course. Each updated file should use a cleaner and more maintainable code structure. Refactored files should have the suffix `_New` to distinguish them from the originals:

- `BinarySearchTree_New.cpp`
- `DivisorCount_New.cpp`
- `DoublyLinkedList_New.c`
- `MergeSort_New.cpp`
- `SegmentedSieve_New.cpp`

#### Refactoring Guidelines
Guidelines for refactoring will be updated as the course progresses, focusing on code readability, organization, and modularity.

---

### Task 2: My Anime List - SOLID Principles and Object-Oriented Design

#### Description
In Task 2, we delve into Object-Oriented Programming principles, specifically the SOLID principles, by creating a simple anime list manager. This task emphasizes best practices in software architecture and clean code while exploring a real-world application scenario.

#### Project Structure
This task is organized into packages to represent different layers of the application:

- **Model**: Defines core data classes, like `Anime`, with attributes like title, genre, and rating.
- **Repository**: Manages in-memory storage of anime and acts as a centralized data repository.
- **Service**: Contains business logic, including filtering and rating, and implements a `Displayable` interface for flexible display options.
- **UI**: Provides a command-line interface for basic user interactions.

#### Features
- **Separation of Concerns**: Each class has a single responsibility, adhering to SOLID principles.
- **Dependency Injection**: Allows easy modification and testing of components.
- **Custom Display**: Anime details can be displayed in various formats.
- **Filtering Options**: Users can filter anime by genre, rating, or other customizable criteria.

#### Future Enhancements
This project can be extended to include API integration for live anime data, a graphical user interface, and additional metadata attributes like release year and studio.

---

### Task 3: My Anime List - MVC Architecture

#### Description
In Task 3, we build upon the previous task by refactoring the anime list manager to implement the **Model-View-Controller (MVC)** architecture. This architecture separates concerns into three layers, making the application more modular, testable, and scalable.

#### Project Structure
- **Model**: Contains the core `Anime` class, encapsulating attributes like title, genre, episodes, and rating.
- **View**: Includes classes responsible for displaying data to the user, like `AnimeDisplayService`.
- **Controller**: Handles user requests and interacts with the model and view via `AnimeService`.
- **Repository**: Manages data persistence and retrieval using the `AnimeRepository`.

#### Features
- **Model**: Encapsulates the core data structure.
- **View**: Provides flexible display options and adheres to the `Displayable` interface.
- **Controller**: Implements business logic like filtering and managing anime.
- **Filters**: Includes reusable strategies for filtering anime by genre and rating.

#### Objective
To refactor the code into the MVC architecture while ensuring it adheres to clean code practices and SOLID principles.

#### Future Enhancements
- **Graphical User Interface (GUI)**: Expand the View layer to include a GUI.
- **Database Integration**: Replace the in-memory repository with a database.
- **Advanced Filters**: Add additional filtering and sorting capabilities.

---


## Guidelines for Each Task

- **Coding Standards**: Follow the coding standards discussed in class.
- **Documentation**: Each task should have a README with an overview, objectives, and any specific instructions.
- **Testing**: Whenever possible, include unit tests to validate functionality and ensure robustness.

## Conclusion

This repository is designed to help you strengthen programming foundations, apply best practices, and create well-structured, maintainable code. Each task builds upon the last, guiding you toward becoming a more skilled and thoughtful developer. Remember: clean code is happy code!

Happy coding! 🚀

---

## License

This project is licensed under the MIT License - see the LICENSE file for details.
```