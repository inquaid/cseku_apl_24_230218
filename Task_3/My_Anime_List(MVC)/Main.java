import model.Anime;
import repository.AnimeRepository;
import service.AnimeService;
import filter.GenreFilter;
import filter.RatingFilter;
import display.AnimeDisplayService;

import java.util.List;

/**
 * Main class to demonstrate the usage of the Anime List project.
 * This class shows the application of SOLID principles in a simple management system.
 */
public class Main {
    public static void main(String[] args) {
        // Initialize the AnimeRepository to store anime data
        AnimeRepository animeRepository = new AnimeRepository();

        // Initialize the animeService for adding, removing, filtering, and displaying anime.
        AnimeService animeService = new AnimeService(animeRepository);

        // Initialize the AnimeDisplayService to display anime data
        AnimeDisplayService displayService = new AnimeDisplayService();

        // Create some sample Anime objects
        Anime anime1 = new Anime("Attack on Titan", "Action", 75, 9.0);
        Anime anime2 = new Anime("One Piece", "Adventure", 1256, 8.5);
        Anime anime3 = new Anime("Naruto", "Action", 220, 8.3);
        Anime anime4 = new Anime("Death Note", "Thriller", 37, 9.5);

        // Add anime to the repository
        animeService.addAnime(anime1);
        animeService.addAnime(anime2);
        animeService.addAnime(anime3);
        animeService.addAnime(anime4);

        // Display all anime in the repository
        System.out.println("All Anime:");
        animeService.displayAnime(displayService);

        // Filter anime by genre and display results
        System.out.println("\nFiltered by Genre (Action):");
        GenreFilter genreFilter = new GenreFilter("Action");
        List<Anime> actionAnime = animeService.filterAnime(genreFilter);
        displayService.display(actionAnime);

        // Filter anime by rating and display results
        System.out.println("\nFiltered by Rating (>= 9.0):");
        RatingFilter ratingFilter = new RatingFilter(9.0);
        List<Anime> highRatedAnime = animeService.filterAnime(ratingFilter);
        displayService.display(highRatedAnime);
    }
}
