use crate::Sorter;

pub struct SelectionSort;

impl<T> Sorter<T> for SelectionSort {
    fn sort(&self, slice: &mut [T]) where
        T: Ord {
        for unsorted in 0..slice.len() {
            let smallest_in_rest = slice[unsorted..]
                .iter()
                .enumerate()
                .min_by_key(|&(_, v)| v)
                .map(|(i, _)| unsorted + i)
                .expect("slice is non-empty");

            if unsorted != smallest_in_rest {
                slice.swap(unsorted, smallest_in_rest);
            }
        }
    }
}