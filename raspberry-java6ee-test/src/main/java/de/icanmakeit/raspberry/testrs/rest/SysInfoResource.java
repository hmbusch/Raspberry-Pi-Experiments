package de.icanmakeit.raspberry.testrs.rest;

import de.icanmakeit.raspberry.testrs.model.SysInfo;
import java.util.Date;
import javax.ejb.Stateless;
import javax.ws.rs.GET;
import javax.ws.rs.Path;
import javax.ws.rs.Produces;
import javax.ws.rs.core.MediaType;
import javax.ws.rs.core.Response;

/**
 *
 * @author Hendrik Busch
 */
@Stateless
@Path("/sysinfo")
@Produces({MediaType.APPLICATION_JSON, MediaType.APPLICATION_XML})
public class SysInfoResource
{
    private static final SysInfo sysInfo = new SysInfo();
    
    @GET
    public Response getSysInfo()
    {
        return Response.ok(sysInfo).expires(new Date(System.currentTimeMillis() + (24*60*60*1000))).build();
    }
}
