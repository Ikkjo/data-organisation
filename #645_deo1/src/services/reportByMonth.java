package services;

import modules.PlumberReport;
import modules.PlumbingJob;
import modules.SortByPlumberID;

import java.time.LocalDateTime;
import java.time.Month;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class reportByMonth {

    public static Map<Month, List<PlumberReport>> getReportForAllMonths(List<PlumbingJob> serviceData) {
        List<PlumberReport> reportForSingleMnth = new ArrayList<PlumberReport>();
        Map<Month, List<PlumberReport>> allReports = new HashMap<Month, List<PlumberReport>>();
        for (int i = 1; i <= 12; i++) {
            List<PlumberReport> report = new ArrayList<PlumberReport>();
            allReports.put(Month.of(i), report);
        }

        for (PlumbingJob job : serviceData) {
            boolean added = false;
            Month jobMonth = LocalDateTime.parse(job.getServiceDateTime(), DateTimeFormatter.ISO_LOCAL_DATE_TIME).getMonth();
            List<PlumberReport> reportsForCurrentMonth = allReports.get(jobMonth);
            for (PlumberReport rep : reportsForCurrentMonth) {
                if (rep.getPlumberID().equals(job.getPlumberID())) {
                    rep.addMonthlyMaterialCost(job.getMaterialCost());
                    rep.addMonthlyEarnings(job.getServicePrice());
                    added = true;
                    break;
                }
            }
            if (!added) {
                PlumberReport report = new PlumberReport(job.getPlumberID(),
                                                         jobMonth,
                                                         job.getServicePrice(),
                                                         job.getMaterialCost());
                allReports.get(jobMonth).add(report);

            }
        }


        List<Month> allMonths = new ArrayList<Month>(allReports.keySet());

        for (Month mth : allMonths) {
            List<PlumberReport> sorted = sortByPlumberID(allReports.get(mth));
            allReports.replace(mth, sorted);
        }
        return allReports;
    }

    private static boolean doesListContainPlumber(List<PlumberReport> reports, String plumberID) {
        boolean contains = false;
        for (PlumberReport plumber : reports) {
            if (plumber.getPlumberID().equals(plumberID)) {
                contains = true;
                break;
            }
        }
        return contains;
    }

    private static List<PlumberReport> sortByPlumberID(List<PlumberReport> data) {
        SortByPlumberID comp = new SortByPlumberID();
        data.sort(comp);
        return data;
    }
}
