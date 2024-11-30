# **Anime Management System**

This project demonstrates a simple **Anime Management System**, designed with a focus on the **Model-View-Controller (MVC)** architecture. The system enables users to manage, filter, and display anime lists while adhering to principles of modular design and clean code.

---

## **Project Features**
- **Add Anime:** Add anime with attributes like title, genre, episode count, and rating.
- **Filter Anime:** Filter anime lists by genre or rating using reusable filters.
- **Display Anime:** Cleanly present anime details in a user-friendly format.
- **Modular Design:** Implemented with strict adherence to the MVC architecture for clear separation of concerns.

---

## **MVC Architecture**
The project strictly adheres to the **MVC architecture** to separate data (Model), business logic (Controller/Service), and presentation (View/Display).

### 1. **Model**
   - Represents the structure of the data (anime details) used in the system.
   - Contains the `Anime` class that encapsulates anime properties like title, genre, and rating.

   **Key Class:**
   - `Anime.java`

### 2. **Repository**
   - Manages storing and retrieving anime data.
   - Acts as the data access layer, abstracting storage mechanics.

   **Key Class:**
   - `AnimeRepository.java`

### 3. **Controller (Service)**
   - Contains the business logic of the application.
   - Processes requests for adding, filtering, and managing anime data.

   **Key Class:**
   - `AnimeService.java`

### 4. **Filter**
   - Implements strategies for filtering anime based on specific criteria (e.g., genre, rating).
   - Encapsulates reusable filter logic through the `FilterStrategy` interface.

   **Key Classes:**
   - `FilterStrategy.java`
   - `GenreFilter.java`
   - `RatingFilter.java`

### 5. **View (Display)**
   - Handles the presentation of anime data to the user.
   - Provides flexibility for customizing display formats via the `Displayable` interface.

   **Key Classes:**
   - `Displayable.java`
   - `AnimeDisplayService.java`

---

## **Directory Structure**

```
src/
├── model/
│   |── Anime.java            # Represents an anime with title, genre, and rating
|   ├── repository/
|   |   └── AnimeRepository.java  # Manages storing and retrieving anime
|   ├── filter/
|   │   ├── FilterStrategy.java   # Interface for filtering anime
|   │   ├── GenreFilter.java      # Filters anime by genre
|   └───└── RatingFilter.java     # Filters anime by rating
├── control/
│   └── AnimeService.java     # Business logic for filtering anime
├── view/
│   ├── Displayable.java      # Interface for displaying anime lists
│   └── AnimeDisplayService.java # Implementation for displaying anime details
└── Main.java                 # test class to demonstrate the project
```

---

## **How to Run the Project**

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/your-repo/anime-management-system.git
   cd anime-management-system
   ```

2. **Run the Application**:
   Compile and run the `Main.java` file. The `Main` class demonstrates the workflow, including adding anime, filtering by criteria, and displaying results.

3. **Sample Output**:
   ```plaintext
   All Anime:
   - Attack on Titan | Genre: Action | Episodes: 75 | Rating: 9.0
   - One Piece       | Genre: Adventure | Episodes: 1256 | Rating: 8.5

   Filtered by Genre (Action):
   - Attack on Titan | Genre: Action | Episodes: 75 | Rating: 9.0

   Filtered by Rating (>= 9.0):
   - Attack on Titan | Genre: Action | Episodes: 75 | Rating: 9.0
   ```

---

## **Why MVC?**
- **Separation of Concerns:** Data, business logic, and presentation are kept separate for better maintainability.
- **Scalability:** New features like additional filters or display mechanisms can be added without impacting other layers.
- **Reusability:** Filters and display interfaces can be reused across different applications.

---

## **Acknowledgments**
Developed as part of a project to demonstrate **Object-Oriented Design Principles** and **MVC Architecture**.

Happy Learning! 🎉
