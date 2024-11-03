package repository;

import model.Anime;
import java.util.ArrayList;
import java.util.List;

/**
 * Repositoy for storing and managing anime data.
 * Provides methods to add, remove, and retrieve anime.
 */
public class AnimeRepository {
    private List<Anime> animeList = new ArrayList<>();  // List to store anime objects

    /**
     * Adds a new anime to the repository
     * @param anime Anime object to be added
     */
    public void addAnime(Anime anime) {
        animeList.add(anime);
    }

    /**
     * Removes an anime from the repository
     * @param anime Anime object to be removed
     */
    public void removeAnime(Anime anime) {
        animeList.remove(anime);
    }

    /**
     * Retrieves the list of all anime in the repository
     * @param title Name of the anime
     * @return  List of anime
     */
    public Anime findAnimeByTitle(String title) {
        return animeList.stream()
                .filter(anime -> anime.getTitle().equalsIgnoreCase(title))
                .findFirst()
                .orElse(null);
    }

    public List<Anime> listAllAnime(){
        return new ArrayList<>(animeList);
    }

}
