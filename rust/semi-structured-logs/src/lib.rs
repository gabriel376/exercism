use std::fmt;

#[derive(Clone, PartialEq, Debug)]
pub enum LogLevel {
    Info,
    Warning,
    Error,
    Debug,
}

impl fmt::Display for LogLevel {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        match self {
            Self::Info => write!(f, "INFO"),
            Self::Warning => write!(f, "WARNING"),
            Self::Error => write!(f, "ERROR"),
            Self::Debug => write!(f, "DEBUG"),
        }
    }
}

pub fn log(level: LogLevel, message: &str) -> String {
    format!("[{level}]: {message}")
}

pub fn info(message: &str) -> String {
    log(LogLevel::Info, message)
}

pub fn warn(message: &str) -> String {
    log(LogLevel::Warning, message)
}

pub fn error(message: &str) -> String {
    log(LogLevel::Error, message)
}
