package filter;

import model.Anime;
import java.util.List;
import java.util.stream.Collectors;

/**
 * Implementation of FilterStrategy for filtering anime by genre.
 */
public class GenreFilter implements FilterStrategy {
    private String genre;   // Genre criterion for filtering

    /**
     * Constructor to set the genre criterion.
     *
     * @param genre Genre to filter by
     */
    public GenreFilter(String genre) {
        this.genre = genre;
    }

    /**
     * Filters the list of anime by the specific genre.
     *
     * @param animeList List of anime to be filtered
     * @return  List of anime that match the genre
     */
    @Override
    public List<Anime> filter(List<Anime> animeList) {
        // Use stream to filter anime by genre
        return animeList.stream()
                .filter(anime -> anime.getGenre().equalsIgnoreCase(genre))
                .collect(Collectors.toList());
    }
}
