pub struct Player {
    pub health: u32,
    pub mana: Option<u32>,
    pub level: u32,
}

impl Player {
    pub fn new(level: u32) -> Player {
        Player {
            health: 100,
            mana: if level < 10 { None } else { Some(100) },
            level,
        }
    }

    pub fn revive(&self) -> Option<Player> {
        if self.health > 0 {
            None
        } else {
            Some(Player::new(self.level))
        }
    }

    pub fn cast_spell(&mut self, mana_cost: u32) -> u32 {
        match self.mana {
            None => {
                self.health = self.health.saturating_sub(mana_cost);
                0
            }
            Some(mana) if mana < mana_cost => 0,
            Some(mana) => {
                self.mana = Some(mana.saturating_sub(mana_cost));
                mana_cost.checked_mul(2).expect("Damage overflow")
            }
        }
    }
}
