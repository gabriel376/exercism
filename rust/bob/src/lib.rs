pub fn reply(message: &str) -> &str {
    let has_alphabetic = message.chars().any(|c| c.is_alphabetic());
    let has_alphanumeric = message.chars().any(|c| c.is_alphanumeric());

    let is_talking = has_alphanumeric;
    let is_yelling = has_alphabetic && message.to_uppercase() == message;
    let is_question = message.trim().ends_with("?");

    match (is_talking, is_yelling, is_question) {
        (_, true, true) => "Calm down, I know what I'm doing!",
        (_, true, _) => "Whoa, chill out!",
        (_, _, true) => "Sure.",
        (false, _, _) => "Fine. Be that way!",
        (_, _, _) => "Whatever.",
    }
}
