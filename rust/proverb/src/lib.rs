pub fn build_proverb(list: &[&str]) -> String {
    match list.len() {
        0 => String::new(),
        _ => format!(
            "{}And all for the want of a {}.",
            (0..list.len() - 1)
                .map(|i| format!("For want of a {} the {} was lost.\n", list[i], list[i + 1]))
                .collect::<Vec<String>>()
                .join(""),
            list[0]
        ),
    }
}
