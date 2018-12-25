hamming <- function(strand1, strand2) {
    strand1.len = nchar(strand1)
    strand2.len = nchar(strand2)

    stopifnot(strand1.len == strand2.len)
    
    strand1.list = strsplit(strand1, "")
    strand2.list = strsplit(strand2, "")

    strand1.vector = unlist(strand1.list)
    strand2.vector = unlist(strand2.list)
    
    diff = strand1.vector != strand2.vector

    sum(diff)
}
