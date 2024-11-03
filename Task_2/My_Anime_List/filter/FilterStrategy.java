package filter;

import model.Anime;
import java.util.List;

/**
 * Interface for defining filtering strategies for anime.
 * Implementations should provide specific filtering logic.
 */
public interface FilterStrategy {

    /**
     * Filters a list of anime based on a specific criterion.
     *
     * @param animeList List of anime to be filtered
     * @return  Filtered list of anime
     */

    List<Anime> filter(List<Anime> animeList);
}
