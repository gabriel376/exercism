use std::collections::HashMap;
use std::cmp::Ordering;

enum ResultType {
    WIN,
    DRAW,
    LOSS,
}

struct Team<'a> {
    wins:   u8,
    draws:  u8,
    losses: u8,
    name:   &'a str,
}

struct TeamResult<'a> {
    name:   &'a str,
    result: ResultType,
}

struct Table;

impl<'a> Team<'a> {
    fn new(name: &'a str) -> Self {
        Team {
            wins:   0,
            draws:  0,
            losses: 0,
            name,
        }
    }

    fn apply(&mut self, result: &TeamResult) {
        match result.result {
            ResultType::WIN  => { self.wins   += 1; },
            ResultType::DRAW => { self.draws  += 1; },
            ResultType::LOSS => { self.losses += 1; },
        }
    }

    fn matches(&self) -> u8 {
        self.wins + self.draws + self.losses
    }

    fn points(&self) -> u8 {
        3 * self.wins + self.draws
    }
}

impl<'a> TeamResult<'a> {
    fn process(line: &'a str) -> Option<[Self; 2]> {
        let parts: Vec<&str> = line.split(';').collect();

        if parts.len() != 3 {
            return None;
        }

        Some([
            TeamResult {
                name:   parts[0],
                result: match parts[2] {
                    "win"  => ResultType::WIN,
                    "draw" => ResultType::DRAW,
                    "loss" => ResultType::LOSS,
                    _     => return None,
                }
            },
            TeamResult {
                name:   parts[1],
                result: match parts[2] {
                    "win"  => ResultType::LOSS,
                    "draw" => ResultType::DRAW,
                    "loss" => ResultType::WIN,
                    _     => return None,
                }
            },
        ])
    }
}

impl Table {
    fn generate(teams: Vec<&Team>) -> String {
        if teams.is_empty() {
            Self::header()
        } else {
            vec!(Self::header(), Self::rows(teams)).join("\n")
        }
    }

    fn header() -> String {
        format!("{:30} | {:>2} | {:>2} | {:>2} | {:>2} | {:>2}",
                "Team",
                "MP",
                "W",
                "D",
                "L",
                "P")
    }

    fn rows(mut teams: Vec<&Team>) -> String {
        teams.sort_by(|a, b| match a.points().cmp(&b.points()).reverse() {
            Ordering::Equal => a.name.cmp(&b.name),
            other => other,
        });

        teams
            .iter()
            .map(|team| Self::row(*team))
            .collect::<Vec<_>>()
            .join("\n")
    }

    fn row(team: &Team) -> String {
        format!("{:30} | {:>2} | {:>2} | {:>2} | {:>2} | {:2}",
                team.name,
                team.matches(),
                team.wins,
                team.draws,
                team.losses,
                team.points())
    }
}

pub fn tally(input: &str) -> String {
    Table::generate(input
        .lines()
        .filter_map(TeamResult::process)
        .flat_map(|[a, b]| vec!(a, b))
        .fold(HashMap::new(), |mut acc, result| {
            acc.entry(result.name)
                .or_insert_with(|| Team::new(&result.name))
                .apply(&result);
            acc
        })
        .values()
        .collect())
}
