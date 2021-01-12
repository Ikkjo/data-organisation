package modules;

import java.util.Comparator;

public class SortByPlumberID implements Comparator<PlumberReport> {

    @Override
    public int compare(PlumberReport o1, PlumberReport o2) {
        return o1.getPlumberID().compareTo(o2.getPlumberID());
    }
}
