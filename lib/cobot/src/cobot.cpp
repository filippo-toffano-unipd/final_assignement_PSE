#include "piece.h"
#include "box.h"
#include "cobot.h"
#include "vision_system.h"

void get_piece_to_box(const uint id_box){
    bool function = true;
    while(function){
    Piece piece_to_box = piece_queue_line1.take_piece();
    // spostamento nella scatola del pezzo afferato
    store_box.load_piece(piece_to_box);

    if(piece_queue_line1.is_empty() /*&& file di imput è finito*/)
        function = false;
    }
}