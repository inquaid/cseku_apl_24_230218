package service;

import model.Anime;
import repository.AnimeRepository;
import filter.FilterStrategy;
import display.Displayable;
import java.util.List;

/**
 * Service layer for managing anime operations.
 * Handles adding, removing, filtering, and displaying anime.
 */
public class AnimeService {
    private AnimeRepository animeRepository;    // Repository for storing anime data

    /**
     * Cpmstructor to inject repository, display service, and filter strategy.
     *
     * @param animeRepository Anime repository for data management
     */
    public AnimeService(AnimeRepository animeRepository) {
        this.animeRepository = animeRepository;
    }

    /**
     * Adds a new anime to the repository
     * @param anime Anime object to be added
     */
    public void addAnime(Anime anime) {
        animeRepository.addAnime(anime);
    }

    /**
     * Removes an existing anime from the repository
     *
     * @param anime Anime object to be removed
     */
    public void removeAnime(Anime anime) {
        animeRepository.removeAnime(anime);
    }

    /**
     * Filters anime in the repository based on the current filter strategy.
     *
     * @param filter Requirement by which the list should be filtered
     * @return  Filtered list of anime
     */
    public List<Anime> filterAnime(FilterStrategy filter) {
        return filter.filter(animeRepository.listAllAnime());
    }

    /**
     * Displays all anime in the repository
     * @param displayService    display service
     */
    public void displayAnime(Displayable displayService) {
        displayService.display(animeRepository.listAllAnime());
    }

}
