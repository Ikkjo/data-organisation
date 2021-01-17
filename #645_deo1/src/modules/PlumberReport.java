package modules;

import com.fasterxml.jackson.annotation.JsonIgnore;

import java.util.List;
import java.util.Map;
import java.time.Month;

public class PlumberReport {
    private String plumberID;
    private Month reportMonth;
    private long materialCostMax;
    private long materialCostMin;
    private long materialCostDiff;
    private long monthlyEarnings;
    private long monthlyMaterialCost;

    public PlumberReport(String plumberID, Month reportMonth, long monthlyEarnings, long monthlyMaterialCost) {
        this.plumberID = plumberID;
        this.monthlyEarnings = monthlyEarnings;
        this.monthlyMaterialCost = monthlyMaterialCost;
        this.reportMonth = reportMonth;
        this.materialCostMin = monthlyMaterialCost;
        this.materialCostMax = monthlyMaterialCost;
        this.materialCostDiff = 0;
    }

    public PlumberReport(String plumberID, Month reportMonth) {
        this.plumberID = plumberID;
        this.reportMonth = reportMonth;
    }

    public String getPlumberID() {
        return plumberID;
    }

    public void setPlumberID(String plumberID) {
        this.plumberID = plumberID;
    }

    public long getMonthlyEarnings() {
        return monthlyEarnings;
    }

    public void setMonthlyEarnings(long monthlyEarnings) {
        this.monthlyEarnings = monthlyEarnings;
    }

    public long getMonthlyMaterialCost() {
        return monthlyMaterialCost;
    }

    public void setMonthlyMaterialCost(long monthlyMaterialCost) {
        this.monthlyMaterialCost = monthlyMaterialCost;
    }

    public void addMonthlyEarnings(long newEarning) {
        this.monthlyEarnings += newEarning;
    }

    public void addMonthlyMaterialCost(long newCost) {
        this.monthlyMaterialCost += newCost;
    }

    public Month getReportMonth() {
        return reportMonth;
    }

    public void setReportMonth(Month reportMonth) {
        this.reportMonth = reportMonth;
    }

    public long getMaterialCostDifference() {
        return materialCostMax - materialCostMin;
    }

    @JsonIgnore
    public long getMaterialCostMax() {
        return materialCostMax;
    }

    @JsonIgnore
    public void setMaterialCostMax(long materialCostMax) {
        if (materialCostMax > this.materialCostMax) {
            this.materialCostMax = materialCostMax;
        }
    }
    @JsonIgnore
    public long getMaterialCostMin() {
        return materialCostMin;
    }
    @JsonIgnore
    public void setMaterialCostMin(long materialCostMin) {
        if (materialCostMin < this.materialCostMin) {
            this.materialCostMin = materialCostMin;
        }
    }
 }
