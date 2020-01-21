use std::char;

const MINE: char = '*';

const ADJACENTS: [(i8, i8); 8] = [
    (-1, -1), (-1, 0), (-1, 1),
    ( 0, -1),          ( 0, 1),
    ( 1, -1), ( 1, 0), ( 1, 1),
];

pub fn annotate(board: &[&str]) -> Vec<String> {
    board
        .iter()
        .enumerate()
        .map(|(x, row)| annotate_row(board, x, row))
        .collect()
}

fn annotate_row(board: &[&str], x: usize, row: &str) -> String {
    row.chars()
        .enumerate()
        .map(|(y, val)| annotate_field(board, x, y, val))
        .collect()
}

fn annotate_field(board: &[&str], x: usize, y: usize, val: char) -> char {
    match val {
        MINE => MINE,
        _ => match count(board, x, y) {
            0 => ' ',
            n => char::from_digit(n as u32, 10).unwrap(),
        }
    }
}

fn count(board: &[&str], x: usize, y: usize) -> usize {
    ADJACENTS
        .iter()
        .filter(|(ox, oy)| is_mine(board, x as i8, y as i8, *ox, *oy))
        .count()
}

fn is_mine(board: &[&str], x: i8, y: i8, ox: i8, oy: i8) -> bool {
    board
        .get((x + ox) as usize)
        .unwrap_or(&"")
        .chars()
        .nth((y + oy) as usize)
        .unwrap_or(' ') == MINE
}
