#include "Bank.h"

// Constructor
Bank::Bank() {
    // Question(std::string _question, std::string _correctAnswer, std::vector<std::string> _answers, int _topic);
    // 0 is math, 1 is science, 2 is music

    easy = {
        // Math questions
        Question("How many eggs would you have if you bought half a dozen?", "6", {"12", "8", "10"}, 0),
        Question("How many textbooks are on a bus of 20 children with 5 textbooks each?", "100", {"20", "4", "120"}, 0),
        Question("If you have to wait for 10 hours, how many minutes will you be waiting?", "600", {"60", "720", "660"}, 0),
        Question("How many feet is a walkway if it is 48 inches in length?", "4", {"3.5", "4.5", "5"}, 0),
        Question("How many quarters are there in 6 dollars?", "24", {"28", "4", "20"}, 0),

        // Science questions
        Question("What do we call molten rock when it is inside the Earth?", "Magma", {"Lava", "Crust", "Volcano"}, 1),
        Question("Wind, water, and ice are all natural forces that cause what?", "Erosion", {"Tornadoes", "Hurricanes", "Earthquakes"}, 1),
        Question("What type of scientist studies erosion, volcanoes, and earthquakes?", "Geologist", {"Chemist", "Physicist", "Biologist"}, 1),
        Question("Which is not an example of a rock?", "Mineral", {"Igneous", "Sedimentary", "Metamorphic"}, 1),
        Question("What is a scientist called that studies space but stays on Earth?", "Astronomer", {"Meteorologist", "Biologist", "Astronaut"}, 1),

        // Music questions
        Question("How many quarter notes are in a whole note?", "4", {"1", "2", "3"}, 2),
        Question("How many eighth notes are in a half note?", "4", {"1", "2", "3"}, 2),
        Question("Which tempo is fastest?", "Presto", {"Adagio", "Moderato"}, 2),
        Question("Which tempo is slowest?", "Largo", {"Moderato", "Vivace"}, 2),
        Question("Which is not a family of instrument?", "Keys", {"Strings", "Brass", "Percussion"}, 2),
        Question("Which dynamic is loudest?", "Fortissimo", {"Forte", "Piano", "Pianissimo"}, 2),
    };

    hard = {
        // Math questions
        Question("If an item costs $2.50 and there's a buy four get one free sale, how much do five cost?", "$10", {"$12.50", "$7.50", "$11.25"}, 0),
        Question("If 1GB of memory can hold 350 songs, how many songs can 2GB of memory hold?", "700", {"750", "900", "1200"}, 0),
        Question("If Joan buys a candy bar for $0.50 every other day, how much will she spend on candy in 2 weeks?", "$3.50", {"$7", "6.50", "12"}, 0),
        Question("How many cookies should be given to each of nine children to evely share a box of three dozen?", "4", {"36", "12", "8"}, 0),
        Question("Driving at a speed of 60mph, how long would it take to drive 270 miles?", "4.5", {"4", "5", "5.5"}, 0),

        // Science questions
        Question("How many planets are in our solar system?", "8", {"7", "9", "10"}, 1),
        Question("Which of the three main sources of energy provides the most calories per gram?", "Fats", {"Carbohydrates", "Protein", "Dairy"}, 1),
        Question("What are the giant slabs of rock which fit together to form the Earth's surface called?", "Tectonic plates", {"Oceans", "Continents"}, 1),
        Question("If a paleontologist excavates an actual bone from a dinosaur, what type of fossil is this called?", "Body fossil", {"Cast", "Trace", "Mold"}, 1),
        Question("What does a 1 mean on the Moh's Scale?", "Soft rock", {"Magnetic rock", "Hard rock", "Rare rock"}, 1),

        // Music questions
        Question("How many eighth notes are in a dotted quarter note?", "3", {"2", "4", "8"}, 2),
        Question("How much longer is a dotted quarter note to a quarter note?", "Eighth", {"Quarter", "Half", "Whole"}, 2),
        Question("How many eighth notes are in a dotted half note?", "6", {"2", "4", "8"}, 2),
        Question("How do you indicate a staccato on a beat?", "Add a dot on top", {"Color the note in", "Write an S above"}, 2),
    };
}

// Get random easy question with specified topic
// 0 is math, 1 is science, 2 is music
Question Bank::getEasyQuestion(int topic) {
    while (1) {
        int randIndex = rand() % easy.size();

        Question q = easy[randIndex];
        if (q.getTopic() == topic) {
            return q;
        }
    }
}

// Get random hard question with specified topic
// 0 is math, 1 is science, 2 is music
Question Bank::getHardQuestion(int topic) {
    while (1) {
        int randIndex = rand() % hard.size();

        Question q = hard[randIndex];
        if (q.getTopic() == topic) {
            return q;
        }
    }
}
