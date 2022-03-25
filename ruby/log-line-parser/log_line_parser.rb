class LogLineParser
  LOG_FORMAT = /\[(?<log_level>INFO|WARNING|ERROR)\]:\s+(?<message>[\w| ]+)\b/

  def initialize(line)
    @line = line
  end

  def message
    @line.match(LOG_FORMAT)[:message]
  end

  def log_level
    @line.match(LOG_FORMAT)[:log_level].downcase()
  end

  def reformat
    "#{message} (#{log_level})"
  end
end
