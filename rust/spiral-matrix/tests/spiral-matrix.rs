use spiral_matrix::*;

#[test]
fn empty_spiral() {
    let expected: Vec<Vec<u32>> = Vec::new();
    assert_eq!(spiral_matrix(0), expected);
}

#[test]
#[ignore]
fn size_one_spiral() {
    let mut expected: Vec<Vec<u32>> = Vec::new();
    expected.push(vec![1]);
    assert_eq!(spiral_matrix(1), expected);
}

#[test]
#[ignore]
fn size_two_spiral() {
    let mut expected: Vec<Vec<u32>> = Vec::new();
    expected.push(vec![1, 2]);
    expected.push(vec![4, 3]);
    assert_eq!(spiral_matrix(2), expected);
}

#[test]
#[ignore]
fn size_three_spiral() {
    let mut expected: Vec<Vec<u32>> = Vec::new();
    expected.push(vec![1, 2, 3]);
    expected.push(vec![8, 9, 4]);
    expected.push(vec![7, 6, 5]);
    assert_eq!(spiral_matrix(3), expected);
}

#[test]
#[ignore]
fn size_four_spiral() {
    let mut expected: Vec<Vec<u32>> = Vec::new();
    expected.push(vec![1,  2,  3,  4]);
    expected.push(vec![12, 13, 14, 5]);
    expected.push(vec![11, 16, 15, 6]);
    expected.push(vec![10,  9, 8,  7]);
    assert_eq!(spiral_matrix(4), expected);
}

#[test]
#[ignore]
fn size_five_spiral() {
    let mut expected: Vec<Vec<u32>> = Vec::new();
    expected.push(vec![1,  2,  3,  4,  5]);
    expected.push(vec![16, 17, 18, 19, 6]);
    expected.push(vec![15, 24, 25, 20, 7]);
    expected.push(vec![14, 23, 22, 21, 8]);
    expected.push(vec![13, 12, 11, 10, 9]);
    assert_eq!(spiral_matrix(5), expected);
}

#[test]
#[ignore]
fn size_ten_spiral() {
    let mut expected: Vec<Vec<u32>> = Vec::new();
    expected.push(vec![1,  2,  3,  4,  5,   6,  7,  8,  9,  10]);
    expected.push(vec![36, 37, 38, 39, 40,  41, 42, 43, 44, 11]);
    expected.push(vec![35, 64, 65, 66, 67,  68, 69, 70, 45, 12]);
    expected.push(vec![34, 63, 84, 85, 86,  87, 88, 71, 46, 13]);
    expected.push(vec![33, 62, 83, 96, 97,  98, 89, 72, 47, 14]);
    expected.push(vec![32, 61, 82, 95, 100, 99, 90, 73, 48, 15]);
    expected.push(vec![31, 60, 81, 94, 93,  92, 91, 74, 49, 16]);
    expected.push(vec![30, 59, 80, 79, 78,  77, 76, 75, 50, 17]);
    expected.push(vec![29, 58, 57, 56, 55,  54, 53, 52, 51, 18]);
    expected.push(vec![28, 27, 26, 25, 24,  23, 22, 21, 20, 19]);
    assert_eq!(spiral_matrix(10), expected);
}
