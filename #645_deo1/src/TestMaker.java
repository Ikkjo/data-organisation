import services.makeYAML;

import java.io.IOException;

public class TestMaker {
    public static void main(String[] args) throws IOException {
        String sep = System.getProperty("file.separator");
        String workingDir = System.getProperty("user.dir");
        String defaultFilePath = workingDir + sep + "resources" + sep + "test1.yaml";
        makeYAML.writeToYAML(makeYAML.userDataInput(), defaultFilePath);
    }
}
