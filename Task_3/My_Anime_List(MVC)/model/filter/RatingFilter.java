package filter;

import model.Anime;
import java.util.List;
import java.util.stream.Collectors;

/**
 * Implementation of FilterStrategy for filtering anime by rating.
 */
public class RatingFilter implements FilterStrategy {

    private double minRating;   // Minimum rating criterion for filtering

    /**
     * Constructor to set the minimum rating criterion.
     *
     * @param minRating Minimum rating to filter by
     */
    public RatingFilter(double minRating) {
        this.minRating = minRating;
    }

    /**
     * Filters the list of anime by the specific minimum rating.
     *
     * @param animeList List of anime to be filtered
     * @return  List of the anime that have a rating equal to or higher than the minimum rating
     */
    @Override
    public List<Anime> filter(List<Anime> animeList) {
        // Use stream to filter anime by rating
        return animeList.stream()
                .filter(anime -> anime.getRating() >= minRating)
                .collect(Collectors.toList());
    }
}
