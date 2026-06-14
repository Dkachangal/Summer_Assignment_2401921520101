package Live;

import music.Playable;
import music.string.veena;
import music.wind.saxophone;

public class test {
    public static void main(String[] args) {
        veena veenaObj = new veena();
        veenaObj.play();

        saxophone saxObj = new saxophone();
        saxObj.play();

        Playable playableRef;

        playableRef = veenaObj;
        playableRef.play();

        playableRef = saxObj;
        playableRef.play();
    }
}