#include <iostream>

enum DogBreed {
    Lab = 0, // starts at 0 and increments by 1 for each enum added
    GoldenRetriever,
    Poodle,
    GermanShepard
};

static void PrintDogBreedMsg(const std::string in_dog_name, const DogBreed in_dog_breed) {
    std::cout << in_dog_name << " is a ";

    switch (in_dog_breed) {
        case Lab:
            std::cout << "Lab" << std::endl;
            break;
        case GoldenRetriever:
            std::cout << "Golden Retriever" << std::endl;
            break;
        case 2: // implicit cast from enum to int
            std::cout << "Poodle" << std::endl;
            break;
        case GermanShepard:
            std::cout << "German Shepard" << std::endl;
            break;
    }
}

int main() {

    std::string roxie_name = "Roxie";
    DogBreed roxie_breed = Lab;
    PrintDogBreedMsg(roxie_name, roxie_breed);

    roxie_breed = static_cast<DogBreed>(2); //explicit cast
    PrintDogBreedMsg(roxie_name, roxie_breed);

    roxie_breed = static_cast<DogBreed>(1);
    PrintDogBreedMsg(roxie_name, roxie_breed);

    if (roxie_breed == 1 &&
        roxie_breed == static_cast<DogBreed>(1)) { // can compare enums to ints
        roxie_breed = GermanShepard;
    }
    PrintDogBreedMsg(roxie_name, roxie_breed);

    return 0;
}
