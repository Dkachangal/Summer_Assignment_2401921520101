package music.wind;

import music.Playable;

public class saxophone implements Playable {
    @Override
    public void play() {
        System.out.println("Playing the Saxophone");
    }
}