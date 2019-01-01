hamming <- function(strand1, strand2) {
    stopifnot(nchar(strand1) == nchar(strand2))
    sum(strsplit(strand1, "")[[1]] != strsplit(strand2, "")[[1]])
}
