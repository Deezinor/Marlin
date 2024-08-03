/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2022 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */

/**
 * Bed Level Tools for Pro UI
<<<<<<< HEAD
 *
 * Based on the original work of: Henri-J-Norden
 * https://github.com/Jyers/Marlin/pull/126
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */

#include "../../../inc/MarlinConfigPre.h"

#if ALL(DWIN_LCD_PROUI, HAS_LEVELING)

#include "../../marlinui.h"
#include "../../../core/types.h"
=======
 * Extended by: Miguel A. Risco-Castillo (MRISCOC)
 * Version: 2.0.0
 * Date: 2022/05/23
 *
 * Based on the original work of: Henri-J-Norden
 * https://github.com/Jyers/Marlin/pull/126
 */

#include "../../../inc/MarlinConfigPre.h"
#include "bedlevel_tools.h"

#if BOTH(DWIN_LCD_PROUI, HAS_LEVELING)

#include "../../marlinui.h"
#include "../../../core/types.h"
#include "dwin.h"
#include "dwinui.h"
#include "dwin_popup.h"
>>>>>>> upstream/bugfix-2.0.x
#include "../../../feature/bedlevel/bedlevel.h"
#include "../../../module/probe.h"
#include "../../../gcode/gcode.h"
#include "../../../module/planner.h"
#include "../../../gcode/queue.h"
#include "../../../libs/least_squares_fit.h"
#include "../../../libs/vector_3.h"

<<<<<<< HEAD
#include "dwin.h"
#include "dwinui.h"
#include "dwin_popup.h"
#include "bedlevel_tools.h"

BedLevelTools bedLevelTools;

#if ENABLED(USE_GRID_MESHVIEWER)
  bool BedLevelTools::viewer_print_value = false;
#endif
bool BedLevelTools::goto_mesh_value = false;
uint8_t BedLevelTools::mesh_x = 0;
uint8_t BedLevelTools::mesh_y = 0;
uint8_t BedLevelTools::tilt_grid = 1;

bool drawing_mesh = false;

#if ENABLED(AUTO_BED_LEVELING_UBL)

  void BedLevelTools::manualValueUpdate(const uint8_t mesh_x, const uint8_t mesh_y, bool undefined/*=false*/) {
    MString<MAX_CMD_SIZE> cmd;
    cmd.set(F("M421 I"), mesh_x, 'J', mesh_y, 'Z', p_float_t(current_position.z, 3));
    if (undefined) cmd += F(" N");
=======
BedLevelToolsClass BedLevelTools;

#if USE_UBL_VIEWER
  bool BedLevelToolsClass::viewer_asymmetric_range = false;
  bool BedLevelToolsClass::viewer_print_value = false;
#endif
bool BedLevelToolsClass::goto_mesh_value = false;
uint8_t BedLevelToolsClass::mesh_x = 0;
uint8_t BedLevelToolsClass::mesh_y = 0;
uint8_t BedLevelToolsClass::tilt_grid = 1;

bool drawing_mesh = false;
char cmd[MAX_CMD_SIZE+16], str_1[16], str_2[16], str_3[16];

#if ENABLED(AUTO_BED_LEVELING_UBL)

  void BedLevelToolsClass::manual_value_update(const uint8_t mesh_x, const uint8_t mesh_y, bool undefined/*=false*/) {
    sprintf_P(cmd, PSTR("M421 I%i J%i Z%s %s"), mesh_x, mesh_y, dtostrf(current_position.z, 1, 3, str_1), undefined ? "N" : "");
>>>>>>> upstream/bugfix-2.0.x
    gcode.process_subcommands_now(cmd);
    planner.synchronize();
  }

<<<<<<< HEAD
  bool BedLevelTools::createPlaneFromMesh() {
    struct linear_fit_data lsf_results;
    incremental_LSF_reset(&lsf_results);
    GRID_LOOP(x, y) {
      const float z = bedlevel.z_values[x][y];
      if (!isnan(z)) {
        xy_pos_t rpos = { bedlevel.get_mesh_x(x), bedlevel.get_mesh_y(y) };
        incremental_LSF(&lsf_results, rpos, z);
=======
  bool BedLevelToolsClass::create_plane_from_mesh() {
    struct linear_fit_data lsf_results;
    incremental_LSF_reset(&lsf_results);
    GRID_LOOP(x, y) {
      if (!isnan(bedlevel.z_values[x][y])) {
        xy_pos_t rpos = { bedlevel.get_mesh_x(x), bedlevel.get_mesh_y(y) };
        incremental_LSF(&lsf_results, rpos, bedlevel.z_values[x][y]);
>>>>>>> upstream/bugfix-2.0.x
      }
    }

    if (finish_incremental_LSF(&lsf_results)) {
      SERIAL_ECHOPGM("Could not complete LSF!");
      return true;
    }

    bedlevel.set_all_mesh_points_to_value(0);

    matrix_3x3 rotation = matrix_3x3::create_look_at(vector_3(lsf_results.A, lsf_results.B, 1));
    GRID_LOOP(i, j) {
<<<<<<< HEAD
      float mx = bedlevel.get_mesh_x(i), my = bedlevel.get_mesh_y(j), mz = bedlevel.z_values[i][j];

      if (DEBUGGING(LEVELING)) {
        DEBUG_ECHOLN(F("before rotation = ["), p_float_t(mx, 7), C(','), p_float_t(my, 7), C(','), p_float_t(mz, 7), F("]   ---> "));
=======
      float mx = bedlevel.get_mesh_x(i),
            my = bedlevel.get_mesh_y(j),
            mz = bedlevel.z_values[i][j];

      if (DEBUGGING(LEVELING)) {
        DEBUG_ECHOPAIR_F("before rotation = [", mx, 7);
        DEBUG_CHAR(',');
        DEBUG_ECHO_F(my, 7);
        DEBUG_CHAR(',');
        DEBUG_ECHO_F(mz, 7);
        DEBUG_ECHOPGM("]   ---> ");
>>>>>>> upstream/bugfix-2.0.x
        DEBUG_DELAY(20);
      }

      rotation.apply_rotation_xyz(mx, my, mz);

      if (DEBUGGING(LEVELING)) {
<<<<<<< HEAD
        DEBUG_ECHOLN(F("after rotation = ["), p_float_t(mx, 7), C(','), p_float_t(my, 7), C(','), p_float_t(mz, 7), F("]   ---> "));
=======
        DEBUG_ECHOPAIR_F("after rotation = [", mx, 7);
        DEBUG_CHAR(',');
        DEBUG_ECHO_F(my, 7);
        DEBUG_CHAR(',');
        DEBUG_ECHO_F(mz, 7);
        DEBUG_ECHOLNPGM("]");
>>>>>>> upstream/bugfix-2.0.x
        DEBUG_DELAY(20);
      }

      bedlevel.z_values[i][j] = mz - lsf_results.D;
    }
    return false;
  }

#else

<<<<<<< HEAD
  void BedLevelTools::manualValueUpdate(const uint8_t mesh_x, const uint8_t mesh_y) {
    gcode.process_subcommands_now(
      TS(F("G29 I"), mesh_x, 'J', mesh_y, 'Z', p_float_t(current_position.z, 3))
    );
=======
  void BedLevelToolsClass::manual_value_update(const uint8_t mesh_x, const uint8_t mesh_y) {
    sprintf_P(cmd, PSTR("G29 I%i J%i Z%s"), mesh_x, mesh_y, dtostrf(current_position.z, 1, 3, str_1));
    gcode.process_subcommands_now(cmd);
>>>>>>> upstream/bugfix-2.0.x
    planner.synchronize();
  }

#endif

<<<<<<< HEAD
void BedLevelTools::manualMove(const uint8_t mesh_x, const uint8_t mesh_y, bool zmove/*=false*/) {
=======
void BedLevelToolsClass::manual_move(const uint8_t mesh_x, const uint8_t mesh_y, bool zmove/*=false*/) {
>>>>>>> upstream/bugfix-2.0.x
  gcode.process_subcommands_now(F("G28O"));
  if (zmove) {
    planner.synchronize();
    current_position.z = goto_mesh_value ? bedlevel.z_values[mesh_x][mesh_y] : Z_CLEARANCE_BETWEEN_PROBES;
    planner.buffer_line(current_position, homing_feedrate(Z_AXIS), active_extruder);
    planner.synchronize();
  }
  else {
<<<<<<< HEAD
    dwinShowPopup(ICON_BLTouch, F("Moving to Point"), F("Please wait until done."));
    hmiSaveProcessID(ID_NothingToDo);
    gcode.process_subcommands_now(TS(F("G0 F300 Z"), p_float_t(Z_CLEARANCE_BETWEEN_PROBES, 3)));
    gcode.process_subcommands_now(TS(F("G42 F4000 I"), mesh_x, F(" J"), mesh_y));
=======
    DWIN_Show_Popup(ICON_BLTouch, F("Moving to Point"), F("Please wait until done."));
    HMI_SaveProcessID(NothingToDo);
    sprintf_P(cmd, PSTR("G0 F300 Z%s"), dtostrf(Z_CLEARANCE_BETWEEN_PROBES, 1, 3, str_1));
    gcode.process_subcommands_now(cmd);
    sprintf_P(cmd, PSTR("G42 F4000 I%i J%i"), mesh_x, mesh_y);
    gcode.process_subcommands_now(cmd);
>>>>>>> upstream/bugfix-2.0.x
    planner.synchronize();
    current_position.z = goto_mesh_value ? bedlevel.z_values[mesh_x][mesh_y] : Z_CLEARANCE_BETWEEN_PROBES;
    planner.buffer_line(current_position, homing_feedrate(Z_AXIS), active_extruder);
    planner.synchronize();
<<<<<<< HEAD
    hmiReturnScreen();
  }
}

// Move / Probe methods.
void BedLevelTools::moveToXYZ() {
  goto_mesh_value = true;
  manualMove(mesh_x, mesh_y, false);
}
void BedLevelTools::moveToXY() {
  goto_mesh_value = false;
  manualMove(mesh_x, mesh_y, false);
}
void BedLevelTools::moveToZ() {
  goto_mesh_value = true;
  manualMove(mesh_x, mesh_y, true);
}
void BedLevelTools::probeXY() {
  gcode.process_subcommands_now(
    MString<MAX_CMD_SIZE>(
      F("G28O\nG0Z"), uint16_t(Z_CLEARANCE_DEPLOY_PROBE),
      F("\nG30X"), p_float_t(bedlevel.get_mesh_x(mesh_x), 2),
      F("Y"), p_float_t(bedlevel.get_mesh_y(mesh_y), 2)
    )
  );
}

void BedLevelTools::meshReset() {
  ZERO(bedlevel.z_values);
  TERN_(AUTO_BED_LEVELING_BILINEAR, bedlevel.refresh_bed_level());
}

// Accessors
float BedLevelTools::getMaxValue() {
  float max = -(__FLT_MAX__);
  GRID_LOOP(x, y) { const float z = bedlevel.z_values[x][y]; if (!isnan(z)) NOLESS(max, z); }
  return max;
}

float BedLevelTools::getMinValue() {
  float min = __FLT_MAX__;
  GRID_LOOP(x, y) { const float z = bedlevel.z_values[x][y]; if (!isnan(z)) NOMORE(min, z); }
  return min;
}

// Return 'true' if mesh is good and within LCD limits
bool BedLevelTools::meshValidate() {
  GRID_LOOP(x, y) {
    const float z = bedlevel.z_values[x][y];
    if (isnan(z) || !WITHIN(z, Z_OFFSET_MIN, Z_OFFSET_MAX)) return false;
  }
  return true;
}

#if ENABLED(USE_GRID_MESHVIEWER)

  constexpr uint8_t meshfont = TERN(TJC_DISPLAY, font8x16, font6x12);

  void BedLevelTools::drawBedMesh(int16_t selected/*=-1*/, uint8_t gridline_width/*=1*/, uint16_t padding_x/*=8*/, uint16_t padding_y_top/*=(40 + 53 - 7)*/) {
    drawing_mesh = true;
    const uint16_t total_width_px = DWIN_WIDTH - padding_x - padding_x,
                   cell_width_px  = total_width_px / (GRID_MAX_POINTS_X),
                   cell_height_px = total_width_px / (GRID_MAX_POINTS_Y);
    const float v_max = abs(getMaxValue()), v_min = abs(getMinValue()), rmax = _MAX(v_min, v_max);

    // Clear background from previous selection and select new square
    dwinDrawRectangle(1, COLOR_BG_BLACK, _MAX(0, padding_x - gridline_width), _MAX(0, padding_y_top - gridline_width), padding_x + total_width_px, padding_y_top + total_width_px);
=======
    HMI_ReturnScreen();
  }
}

void BedLevelToolsClass::MoveToXYZ() {
  BedLevelTools.goto_mesh_value = true;
  BedLevelTools.manual_move(BedLevelTools.mesh_x, BedLevelTools.mesh_y, false);
}
void BedLevelToolsClass::MoveToXY() {
  BedLevelTools.goto_mesh_value = false;
  BedLevelTools.manual_move(BedLevelTools.mesh_x, BedLevelTools.mesh_y, false);
}
void BedLevelToolsClass::MoveToZ() {
  BedLevelTools.goto_mesh_value = true;
  BedLevelTools.manual_move(BedLevelTools.mesh_x, BedLevelTools.mesh_y, true);
}
void BedLevelToolsClass::ProbeXY() {
  sprintf_P(cmd, PSTR("G30X%sY%s"),
    dtostrf(bedlevel.get_mesh_x(BedLevelTools.mesh_x), 1, 2, str_1),
    dtostrf(bedlevel.get_mesh_y(BedLevelTools.mesh_y), 1, 2, str_2)
  );
  gcode.process_subcommands_now(cmd);
}

float BedLevelToolsClass::get_max_value() {
  float max = __FLT_MAX__ * -1;
  GRID_LOOP(x, y) {
    if (!isnan(bedlevel.z_values[x][y]) && bedlevel.z_values[x][y] > max)
      max = bedlevel.z_values[x][y];
  }
  return max;
}

float BedLevelToolsClass::get_min_value() {
  float min = __FLT_MAX__;
  GRID_LOOP(x, y) {
    if (!isnan(bedlevel.z_values[x][y]) && bedlevel.z_values[x][y] < min)
      min = bedlevel.z_values[x][y];
  }
  return min;
}

bool BedLevelToolsClass::meshvalidate() {
  float min = __FLT_MAX__, max = __FLT_MAX__ * -1;

  GRID_LOOP(x, y) {
    if (isnan(bedlevel.z_values[x][y])) return false;
    if (bedlevel.z_values[x][y] < min) min = bedlevel.z_values[x][y];
    if (bedlevel.z_values[x][y] > max) max = bedlevel.z_values[x][y];
  }
  return WITHIN(max, MESH_Z_OFFSET_MIN, MESH_Z_OFFSET_MAX);
}

#if USE_UBL_VIEWER

  void BedLevelToolsClass::Draw_Bed_Mesh(int16_t selected /*= -1*/, uint8_t gridline_width /*= 1*/, uint16_t padding_x /*= 8*/, uint16_t padding_y_top /*= 40 + 53 - 7*/) {
    drawing_mesh = true;
    const uint16_t total_width_px = DWIN_WIDTH - padding_x - padding_x;
    const uint16_t cell_width_px  = total_width_px / (GRID_MAX_POINTS_X);
    const uint16_t cell_height_px = total_width_px / (GRID_MAX_POINTS_Y);
    const float v_max = abs(get_max_value()), v_min = abs(get_min_value()), range = _MAX(v_min, v_max);

    // Clear background from previous selection and select new square
    DWIN_Draw_Rectangle(1, Color_Bg_Black, _MAX(0, padding_x - gridline_width), _MAX(0, padding_y_top - gridline_width), padding_x + total_width_px, padding_y_top + total_width_px);
>>>>>>> upstream/bugfix-2.0.x
    if (selected >= 0) {
      const auto selected_y = selected / (GRID_MAX_POINTS_X);
      const auto selected_x = selected - (GRID_MAX_POINTS_X) * selected_y;
      const auto start_y_px = padding_y_top + selected_y * cell_height_px;
      const auto start_x_px = padding_x + selected_x * cell_width_px;
<<<<<<< HEAD
      dwinDrawRectangle(1, COLOR_WHITE, _MAX(0, start_x_px - gridline_width), _MAX(0, start_y_px - gridline_width), start_x_px + cell_width_px, start_y_px + cell_height_px);
    }

    // Draw value square grid
=======
      DWIN_Draw_Rectangle(1, Color_White, _MAX(0, start_x_px - gridline_width), _MAX(0, start_y_px - gridline_width), start_x_px + cell_width_px, start_y_px + cell_height_px);
    }

    // Draw value square grid
    char buf[8];
>>>>>>> upstream/bugfix-2.0.x
    GRID_LOOP(x, y) {
      const auto start_x_px = padding_x + x * cell_width_px;
      const auto end_x_px   = start_x_px + cell_width_px - 1 - gridline_width;
      const auto start_y_px = padding_y_top + ((GRID_MAX_POINTS_Y) - y - 1) * cell_height_px;
      const auto end_y_px   = start_y_px + cell_height_px - 1 - gridline_width;
<<<<<<< HEAD
      const float z = bedlevel.z_values[x][y];
      const uint16_t color = isnan(z) ? COLOR_GREY : (   // Gray if undefined
        (z < 0 ? uint16_t(round(0x1F * -z / rmax)) << 11 // Red for negative mesh point
               : uint16_t(round(0x3F *  z / rmax)) << 5) // Green for positive mesh point
               | _MIN(0x1F, (uint8_t(abs(z) * 0.4)))     // + Blue stepping for every mm
      );

      dwinDrawRectangle(1, color, start_x_px, start_y_px, end_x_px, end_y_px);

=======
      DWIN_Draw_Rectangle(1,                                                                                 // RGB565 colors: http://www.barth-dev.de/online/rgb565-color-picker/
        isnan(bedlevel.z_values[x][y]) ? Color_Grey : (                                                           // gray if undefined
          (bedlevel.z_values[x][y] < 0 ?
            (uint16_t)round(0x1F * -bedlevel.z_values[x][y] / (!viewer_asymmetric_range ? range : v_min)) << 11 : // red if mesh point value is negative
            (uint16_t)round(0x3F *  bedlevel.z_values[x][y] / (!viewer_asymmetric_range ? range : v_max)) << 5) | // green if mesh point value is positive
              _MIN(0x1F, (((uint8_t)abs(bedlevel.z_values[x][y]) / 10) * 4))),                                    // + blue stepping for every mm
        start_x_px, start_y_px, end_x_px, end_y_px
      );

>>>>>>> upstream/bugfix-2.0.x
      safe_delay(10);
      LCD_SERIAL.flushTX();

      // Draw value text on
<<<<<<< HEAD
      if (!viewer_print_value) continue;

      const uint8_t fs = DWINUI::fontWidth(meshfont);
      const int8_t offset_y = cell_height_px / 2 - fs;
      if (isnan(z)) { // undefined
        dwinDrawString(false, meshfont, COLOR_WHITE, COLOR_BG_BLUE, start_x_px + cell_width_px / 2 - 5, start_y_px + offset_y, F("X"));
      }
      else {          // has value
        MString<12> msg;
        constexpr bool is_wide = (GRID_MAX_POINTS_X) >= TERN(TJC_DISPLAY, 8, 10);
        if (is_wide)
          msg.setf(F("%02i"), uint16_t(z * 100) % 100);
        else
          msg.set(p_float_t(abs(z), 2));
        const int8_t offset_x = cell_width_px / 2 - (fs / 2) * msg.length() - 2;
        if (is_wide)
          dwinDrawString(false, meshfont, COLOR_WHITE, COLOR_BG_BLUE, start_x_px - 2 + offset_x, start_y_px + offset_y, F("."));
        dwinDrawString(false, meshfont, COLOR_WHITE, COLOR_BG_BLUE, start_x_px + 1 + offset_x, start_y_px + offset_y, msg);
      }

      safe_delay(10);
      LCD_SERIAL.flushTX();

    } // GRID_LOOP
  }

  void BedLevelTools::setMeshViewerStatus() { // TODO: draw gradient with values as a legend instead
    float v_max = abs(getMaxValue()), v_min = abs(getMinValue()), rmax = _MAX(v_min, v_max), rmin = _MIN(v_min, v_max);
    if (rmax > 3e+10f) rmax = 0.0000001f;
    if (rmin > 3e+10f) rmin = 0.0000001f;
    ui.set_status(&MString<47>(F("Red "),  p_float_t(-rmax, 3), F("..0.."), p_float_t(rmin, 3), F(" Green")));
    drawing_mesh = false;
  }

#endif // USE_GRID_MESHVIEWER
=======
      if (viewer_print_value) {
        int8_t offset_x, offset_y = cell_height_px / 2 - 6;
        if (isnan(bedlevel.z_values[x][y])) {  // undefined
          DWIN_Draw_String(false, font6x12, Color_White, Color_Bg_Blue, start_x_px + cell_width_px / 2 - 5, start_y_px + offset_y, F("X"));
        }
        else {                          // has value
          if (GRID_MAX_POINTS_X < 10)
            sprintf_P(buf, PSTR("%s"), dtostrf(abs(bedlevel.z_values[x][y]), 1, 2, str_1));
          else
            sprintf_P(buf, PSTR("%02i"), (uint16_t)(abs(bedlevel.z_values[x][y] - (int16_t)bedlevel.z_values[x][y]) * 100));
          offset_x = cell_width_px / 2 - 3 * (strlen(buf)) - 2;
          if (!(GRID_MAX_POINTS_X < 10))
            DWIN_Draw_String(false, font6x12, Color_White, Color_Bg_Blue, start_x_px - 2 + offset_x, start_y_px + offset_y /*+ square / 2 - 6*/, F("."));
          DWIN_Draw_String(false, font6x12, Color_White, Color_Bg_Blue, start_x_px + 1 + offset_x, start_y_px + offset_y /*+ square / 2 - 6*/, buf);
        }
        safe_delay(10);
        LCD_SERIAL.flushTX();
      }
    }
  }

  void BedLevelToolsClass::Set_Mesh_Viewer_Status() { // TODO: draw gradient with values as a legend instead
    float v_max = abs(get_max_value()), v_min = abs(get_min_value()), range = _MAX(v_min, v_max);
    if (v_min > 3e+10F) v_min = 0.0000001;
    if (v_max > 3e+10F) v_max = 0.0000001;
    if (range > 3e+10F) range = 0.0000001;
    char msg[46];
    if (viewer_asymmetric_range) {
      dtostrf(-v_min, 1, 3, str_1);
      dtostrf( v_max, 1, 3, str_2);
    }
    else {
      dtostrf(-range, 1, 3, str_1);
      dtostrf( range, 1, 3, str_2);
    }
    sprintf_P(msg, PSTR("Red %s..0..%s Green"), str_1, str_2);
    ui.set_status(msg);
    drawing_mesh = false;
  }

#endif // USE_UBL_VIEWER
>>>>>>> upstream/bugfix-2.0.x

#endif // DWIN_LCD_PROUI && HAS_LEVELING
