/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package de.icanmakeit.raspberry.testrs.rest;

import java.util.Date;
import javax.ejb.Stateless;
import javax.ws.rs.GET;
import javax.ws.rs.Path;
import javax.ws.rs.Produces;
import javax.ws.rs.core.MediaType;
import javax.ws.rs.core.Response;

/**
 *
 * @author Hendrik
 */
@Stateless
@Path("sysinfo")
@Produces({MediaType.APPLICATION_JSON, MediaType.APPLICATION_XML})
public class SysInfoResource
{
    @GET
    public Response getSysInfo()
    {
        return Response.ok("sysinfo").expires(new Date(System.currentTimeMillis() + (24*60*60*1000))).build();
    }
}
