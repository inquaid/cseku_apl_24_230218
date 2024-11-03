package display;

import model.Anime;
import java.util.List;

/**
 * Interface for displaying a list of anime.
 * Implementations should define how the anime list is presented
 */
public interface Displayable {

    /**
     * Displays the provided list of anime.
     *
     * @param animeList List of anime to be displayed
     */
    void display(List<Anime> animeList);
}
