package model;

/**
 * Represents an anime entry.
 * Contains information about the anime like title, genre, rating etc.
 */

public class Anime {
    private String title;   // Title of the anime
    private String genre;   // Genre of the anime
    private int episodes;   // Episodes of the anime
    private double rating;  // Rating of the anime

    /**
     *
     * @param title     Title of the anime
     * @param genre     Genre of the anime
     * @param episodes  Episode count of the anime
     * @param rating    Rating of the anime
     */

    public Anime(String title, String genre, int episodes, double rating) {
        this.title = title;
        this.genre = genre;
        this.episodes = episodes;
        this.rating = rating;
    }

    // Getters and Setters for accessing and modifying anime details
    public String getTitle() {
        return title;
    }

    public String getGenre() {
        return genre;
    }

    public int getEpisodes() {
        return episodes;
    }

    public double getRating() {
        return rating;
    }
}
