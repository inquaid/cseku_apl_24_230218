package display;

import model.Anime;
import java.util.List;

/**
 * Implementation of the Displayable interface.
 * Provides methods to display anime details in a simple format.
 */
public class AnimeDisplayService implements Displayable {

    /**
     * Displays the list of anime with their details.
     *
     * @param animeList List of anime to be displayed
     */
    @Override
    public void display(List<Anime> animeList) {
        for (Anime anime : animeList) {
            // Display the title, genre, and rating of each anime
            System.out.println("Title: " + anime.getTitle() +
                    ", Genre: " + anime.getGenre() +
                    ", Episodes: " + anime.getEpisodes() +
                    ", Rating: " + anime.getRating());
        }
    }
}
