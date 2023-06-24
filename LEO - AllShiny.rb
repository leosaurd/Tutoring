BallHandlers::OnCatch.add(:POKEBALL,proc{|ball,battle,pokemon|
   pokemon.makeShiny
})
