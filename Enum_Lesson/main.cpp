#include <iostream>

enum DogBreed {
    Lab = 0, // starts at 0 and increments by 1 for each enum added
    GoldenRetriever,
    Poodle,
    GermanShepard
};

static std::string DogBreed_ToString(const DogBreed in_dog_breed)
{
    switch (in_dog_breed) {
        case Lab:
            return "Lab";
        case GoldenRetriever:
            return "Golden Retriever";
        case 2: // implicit cast from enum to int
            return "Poodle";
        case GermanShepard:
            return "German Shepard";
    }
    return "Invalid Dog Breed";
}

void PrintAllBreeds() {
    std::cout << "The dog breeds are ";
    for (int i = Lab; i < GermanShepard; i++) {
        std::cout << DogBreed_ToString(static_cast<DogBreed>(i)) << ", ";
    }
    std::cout << "and " << DogBreed_ToString(GermanShepard) << "." << std:: endl;
}

static void PrintDogBreedMsg(const std::string in_dog_name, const DogBreed in_dog_breed) {
    std::cout << in_dog_name << " is a " << DogBreed_ToString(in_dog_breed) << "." << std::endl;
}



int main() {

    PrintAllBreeds();

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
