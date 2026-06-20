public class TestCompartment {
    public static void main(String[] args) {
        Compartment[] train = new Compartment[10];

        for (int i = 0; i < train.length; i++) {
            int randomNum = (int) (Math.random() * 4) + 1;

            switch (randomNum) {
                case 1:
                    train[i] = new FirstClass();
                    break;
                case 2:
                    train[i] = new Ladies();
                    break;
                case 3:
                    train[i] = new General();
                    break;
                case 4:
                    train[i] = new Luggage();
                    break;
            }
        }
        System.out.println("--- Train Coach Notice Board ---");
        for (int i = 0; i < train.length; i++) {
            System.out.println("Coach " + (i + 1) + ": " + train[i].notice());
        }
    }
}
