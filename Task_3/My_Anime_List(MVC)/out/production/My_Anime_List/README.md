# **My Anime List - SOLID Principles Project**

## **Overview**
This project is a simple anime management system built to demonstrate a clear understanding of the SOLID principles in Object-Oriented Design. The application allows you to store, display, and filter anime using a set of well-defined classes and interfaces that follow SOLID guidelines.

## **Table of Contents**
- [Overview](#overview)
- [Features](#features)
- [SOLID Principles Explained](#solid-principles-explained)
- [Project Structure](#project-structure)
- [How to Run](#how-to-run)
- [Technologies Used](#technologies-used)
- [Future Improvements](#future-improvements)

## **Features**
- Add anime to a repository.
- Display all anime in a well-formatted manner.
- Filter anime by genre or rating.
- Demonstrates the correct usage of SOLID principles.

## **SOLID Principles Explained**
1. **Single Responsibility Principle (SRP)**:
    - Each class has a single responsibility.
    - Example: `Anime` class holds only anime details, while `AnimeService` handles filtering.

2. **Open/Closed Principle (OCP)**:
    - Classes are open for extension but closed for modification.
    - Example: Filtering logic is extensible with new `FilterStrategy` implementations without modifying existing code.

3. **Liskov Substitution Principle (LSP)**:
    - Subclasses or implementations should be replaceable for their base classes.
    - Example: `AnimeService` uses `FilterStrategy` interface, allowing different filter types like `GenreFilter` or `RatingFilter`.

4. **Interface Segregation Principle (ISP)**:
    - Interfaces should be specific and not force the implementation of unused methods.
    - Example: `Displayable` interface is small and only focuses on the display of anime.

5. **Dependency Inversion Principle (DIP)**:
    - High-level modules should not depend on low-level modules; both should depend on abstractions.
    - Example: `AnimeService` relies on abstractions (`FilterStrategy` and `Displayable`) rather than concrete classes.

## **Project Structure**
```
src/
├── model/
│   └── Anime.java            # Represents an anime with title, genre, and rating
├── repository/
│   └── AnimeRepository.java  # Manages storing and retrieving anime
├── service/
│   └── AnimeService.java     # Business logic for filtering anime
├── filter/
│   ├── FilterStrategy.java   # Interface for filtering anime
│   ├── GenreFilter.java      # Filters anime by genre
│   └── RatingFilter.java     # Filters anime by rating
├── display/
│   ├── Displayable.java      # Interface for displaying anime lists
│   └── AnimeDisplayService.java # Implementation for displaying anime details
└── Main.java                 # Main class to demonstrate the project
```

## **How to Run**
1. **Clone the repository**:
   ```bash
   git clone https://github.com/inquaid/my-anime-list.git
   ```
2. **Open the project** in your preferred Java IDE (e.g., IntelliJ IDEA).
3. **Build and run** the `Main.java` file to see the SOLID principles in action.

## **Technologies Used**
- **Java**: The programming language used for this project.
- **IntelliJ IDEA**: Recommended IDE for development.
- **Git**: Version control system to manage project files.

## **Future Improvements**
- Add a user interface (UI) for better interaction.
- Implement more complex filtering (e.g., by release year, popularity).
- Integrate a database for persistent storage.
- Add additional sorting options (e.g., alphabetical, by rating).

## **Contributing**
Feel free to fork this project, submit issues, or create pull requests if you have any suggestions or improvements.

## **License**
This project is open-source and available under the [MIT License](LICENSE).
