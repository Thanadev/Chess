#include "playertest.h"

PlayerTest::PlayerTest()
{
    player = new Player(true);
    pawn = new PawnEntity(Position(0,0), true);
    pawn2 = new PawnEntity(Position(1,0), true);
}

PlayerTest::~PlayerTest()
{
    delete player;
    delete pawn;
    delete pawn2;
}

void PlayerTest::runTests()
{
    qDebug() << "Player tests";
    Q_ASSERT_X(getPiecesTest(), "removePieceTest", "");
    Q_ASSERT_X(removePieceTest(), "removePieceTest", "");
}

bool PlayerTest::removePieceTest()
{
    bool isValid = false;

    player->addPiece(pawn);

    if (player->removePiece(pawn) && player->getPieces()->size() == 0) {
        isValid = true;
    }

    return isValid;
}

bool PlayerTest::getPiecesTest()
{
    player->addPiece(pawn);
    player->addPiece(pawn2);

    bool isValid = player->getPieces()->size() == 2;
    player->getPieces()->clear();

    return isValid;
}
