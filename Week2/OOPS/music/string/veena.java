package music.string;

import music.Playable;

public class veena implements Playable {
    @Override
    public void play() {
        System.out.println("Playing the Veena");
    }
}