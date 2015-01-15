/* GLOBAL GLACIER MASS-BALNCE MODEL*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<netcdf.h>


int main()

{

float temp_series_glac[5]={1,2,3,4,5};
float prec_series_glac[5]={10,20,30,40,50};
float testdata[2][3]={{1,2},{3,4,5}};

printf("%f\n",temp_series_glac[1]);


#define FILE_NAME "testdata.nc"

/* We are writing 2D data, a 6 x 12 grid. */
#define NDIMS 2
#define NX 2
#define NY 3

/* Handle errors by printing an error message and exiting with a
 * non-zero status. */
#define ERRCODE 2
#define ERR(e) {printf("Error: %s\n", nc_strerror(e)); exit(ERRCODE);}

 int retval, ncid, varid, x_dimid, y_dimid, dimids[2];

/* Create the file. The NC_CLOBBER parameter tells netCDF to
    * overwrite this file, if it already exists.*/
   if ((retval = nc_create(FILE_NAME, NC_CLOBBER, &ncid)))
      ERR(retval);

 /* Define the dimensions. NetCDF will hand back an ID for each. */
   if ((retval = nc_def_dim(ncid, "x", NX, &x_dimid)))
      ERR(retval);
   if ((retval = nc_def_dim(ncid, "y", NY, &y_dimid)))
      ERR(retval);
      
 /* The dimids array is used to pass the IDs of the dimensions of
    * the variable. */
   dimids[0] = x_dimid;
   dimids[1] = y_dimid;

   /* Define the variable. The type of the variable in this case is
    * NC_INT (4-byte integer). */
   if ((retval = nc_def_var(ncid, "data", NC_INT, NDIMS, 
			    dimids, &varid)))
      ERR(retval);   
      
   /* End define mode. This tells netCDF we are done defining
    * metadata. */
   if ((retval = nc_enddef(ncid)))
      ERR(retval);


 return 0;
}

