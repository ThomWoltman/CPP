
#include "Headers/Game.h"
#include "Libs/CsvReader.h"
#include "Headers/State/Haven_state.h"

using namespace std;
int main() {

    Game game(1000000, "Roatan", Haven_state());
    game.run();
    CsvReader reader;
    auto data = reader.getCities();
    cout << data.empty() << endl;

    return 0;
}