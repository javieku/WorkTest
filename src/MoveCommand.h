#pragma once

#include "CommandInterface.h"
#include "Gameplay.h"

namespace Game
{
class MoveCommand : public CommandInterface
{
public:
    MoveCommand( const Cell& cell, const Coordinates& to );
    ~MoveCommand( ) = default;

    bool is_valid( const Gameplay& gameplay ) const override;
    bool is_finished( const Gameplay& gameplay ) const override;
    bool apply( Gameplay& gameplay ) override;
    bool undo( Gameplay& gameplay ) override;

private:
    Cell m_cell;
    Coordinates m_to_coordinates;

    // Undo
    Cell m_previous_cell;
    bool m_store_for_undo;
};
using MoveCommandSharedPtr = std::shared_ptr< MoveCommand >;
}