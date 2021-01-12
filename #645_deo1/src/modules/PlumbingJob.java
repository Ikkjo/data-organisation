package modules;
import java.util.Objects;

public class PlumbingJob {
    private String jobNum;
    private String plumberID;
    private long materialCost;
    private long servicePrice;
    private String serviceDateTime;

    public PlumbingJob() {
    }

    public PlumbingJob(String jobNum, String plumberID, long materialCost, long servicePrice, String serviceDateTime) {
        this.jobNum = jobNum;
        this.plumberID = plumberID;
        this.materialCost = materialCost;
        this.servicePrice = servicePrice;
        this.serviceDateTime = serviceDateTime;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        PlumbingJob plumbingJob = (PlumbingJob) o;
        return getMaterialCost() == plumbingJob.getMaterialCost() && getServicePrice() == plumbingJob.getServicePrice() && getJobNum().equals(plumbingJob.getJobNum()) && getPlumberID().equals(plumbingJob.getPlumberID()) && getServiceDateTime().equals(plumbingJob.getServiceDateTime());
    }

    @Override
    public int hashCode() {
        return Objects.hash(getJobNum(), getPlumberID(), getMaterialCost(), getServicePrice(), getServiceDateTime());
    }

    public String getJobNum() {
        return jobNum;
    }

    public void setJobNum(String jobNum) {
        this.jobNum = jobNum;
    }

    public String getPlumberID() {
        return plumberID;
    }

    public void setPlumberID(String plumberID) {
        this.plumberID = plumberID;
    }

    public long getMaterialCost() {
        return materialCost;
    }

    public void setMaterialCost(long materialCost) {
        this.materialCost = materialCost;
    }

    public long getServicePrice() {
        return servicePrice;
    }

    public void setServicePrice(long servicePrice) {
        this.servicePrice = servicePrice;
    }

    public String getServiceDateTime() {
        return serviceDateTime;
    }

    public void setServiceDateTime(String serviceDateTime) {
        this.serviceDateTime = serviceDateTime;
    }
}
