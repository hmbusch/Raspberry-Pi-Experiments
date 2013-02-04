package de.icanmakeit.raspberry.testrs.model;

import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlRootElement;

/**
 *
 * @author Hendrik Busch
 */
@XmlRootElement
public class SysInfo
{
    @XmlElement
    public String getJavaHome()
    {
        return System.getProperty("java.home");
    }
    
    @XmlElement
    public int getProcessorCount()
    {
        return Runtime.getRuntime().availableProcessors();
    }
    
    @XmlElement
    public String getJavaRuntime()
    {
        return System.getProperty("java.runtime.name") + " " + System.getProperty("java.runtime.version");
    }
    
    @XmlElement
    public String getOsName()
    {
         return System.getProperty("os.name");
    }
}
